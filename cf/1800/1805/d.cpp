#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
vector<int> edge[N];
int d1[N], d2[N];
int z1[N], z2[N];
int ans[N];
int fa[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void dfs(int x, int fa, int *d) {
    d[x] = d[fa] + 1;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x, d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0, d1);
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        if (d1[p] < d1[i]) {
            p = i;
        }
    }
    int p1 = p;
    dfs(p, 0, d1);
    p = 1;
    for (int i = 1; i <= n; ++i) {
        if (d1[p] < d1[i]) {
            p = i;
        }
    }
    int p2 = p;
    dfs(p, 0, d2);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        z1[i] = i;
        z2[i] = i;
    }
    sort(z1 + 1, z1 + n + 1, [&](const int &a, const int &b) {
        return d1[a] < d1[b];
    });
    sort(z2 + 1, z2 + n + 1, [&](const int &a, const int &b) {
        return d2[a] < d2[b];
    });
    // cout << endl;
    // cout << p1 << ' ' << p2 << endl;
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << "   " << z1[i] << ' ' << z2[i] << endl;
    // }
    int m = n;
    int pt1 = n, pt2 = n;
    for (int i = n; i >= 1; --i) {
        while (pt1 >= 1 && d1[z1[pt1]] - 1 >= i) {
            int u = find(p1), v = find(z1[pt1]);
            // cout << z1[pt1] << ' ';
            if (u != v) {
                --m;
                fa[u] = v;
            }
            --pt1;
        }
        // cout << " ------ ";
        while (pt2 >= 1 && d2[z2[pt2]] - 1 >= i) {
            int u = find(p2), v = find(z2[pt2]);
            // cout << z2[pt2] << ' ';
            if (u != v) {
                --m;
                fa[u] = v;
            }
            --pt2;
        }
        // cout << endl;
        ans[i] = m;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}