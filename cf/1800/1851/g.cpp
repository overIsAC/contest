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
const int N = 3 + 2e5;

int h[N];
vector<int> e[N], edge[N];
int n, m;
int f[N][20], mx[N][20], d[N];
int fa[N];

int find(int p) {
    return fa[p] == p ? fa[p] : fa[p] = find(fa[p]);
}

void dfs(int x, int fa) {
    d[x] = d[fa] + 1;
    for (int i = 1; i < 20; ++i) {
        mx[x][i] = max(mx[x][i - 1], mx[f[x][i - 1]][i - 1]);
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        f[y][0] = x;
        mx[y][0] = h[y];
        dfs(y, x);
    }
}

int get(int x, int y) {
    int ans = max(h[x], h[y]);
    if (d[x] > d[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; --i) {
        if (d[x] <= d[f[y][i]]) {
            ans = max(ans, mx[y][i]);
            y = f[y][i];
        }
    }
    ans = max(ans, h[x]);
    ans = max(ans, h[y]);
    if (x == y) {
        return ans;
    }
    for (int i = 19; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            ans = max(mx[x][i], ans);
            ans = max(mx[y][i], ans);
            x = f[x][i];
            y = f[y][i];
        }
    }
    x = f[x][0];
    ans = max(ans, h[x]);
    return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];

        e[i].clear();
        edge[i].clear();
        fa[i] = i;
        d[i] = 0;
        memset(f[i], 0, sizeof(f[i]));
        memset(mx[i], 0, sizeof(mx[i]));
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> p(n);
    for (int i = 1; i <= n; ++i) {
        p[i - 1] = i;
    }
    sort(p.begin(), p.end(), [&](int u, int v) {
        return h[u] < h[v];
    });
    for (auto x : p) {
        for (auto &y : e[x]) {
            int u = find(x), v = find(y);
            if (u == v) {
                continue;
            }
            fa[u] = v;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            dfs(i, 0);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (find(a) != find(b)) {
            cout << "NO" << endl;
            continue;
        }
        int t = get(a, b);
        if (t - h[a] > c) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}