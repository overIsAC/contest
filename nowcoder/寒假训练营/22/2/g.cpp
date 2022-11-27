#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, m;
int f[N][20];
int d[N];
vector<int> edge[N];
int a[N];

LL o[N][2];

void dfs(int x, int fa) {
    d[x] = d[fa] + 1;
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        f[y][0] = x;
        for (int i = 1; i < 20; ++i) {
            f[y][i] = f[f[y][i - 1]][i - 1];
        }
        o[y][0] += o[x][0];
        if (a[y] > a[x]) {
            o[y][0] += a[y] - a[x];
        }
        o[y][1] += o[x][1];
        if (a[x] > a[y]) {
            o[y][1] += a[x] - a[y];
        }
        dfs(y, x);
    }
}

int lca(int x, int y) {
    if (d[x] > d[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; --i) {
        if (d[x] <= d[f[y][i]]) {
            y = f[y][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 19; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i= 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    // for (int i= 1; i <= n; ++i) {
    //     for (int j= i ; j <= n; ++j) {
    //         cout << i << " " << j << " " << lca(i, j) << endl;
    //     }
    // }

    while (m--) {
        int x, y;
        cin >> x >> y;
        int g = lca(x, y);
        cout << a[x] + o[x][1] - o[g][1] + o[y][0] - o[g][0] << endl;
    }
    return 0;
}