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

vector<int> edge[N];
int f[N][20];
int n, d[N];
int q;
int sz[N];

void dfs(int x, int fa) {
    f[x][0] = fa;
    d[x] = d[fa] + 1;
    int leaf = 0;
    sz[x] = 0;
    for (int i = 1; i < 20; ++i) {
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        leaf = 1;
        sz[x] += sz[y];
    }
    if (!leaf) {
        ++sz[x];
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; --i) {
        if (d[f[x][i]] >= d[y]) {
            x = f[x][i];
        }
    }
    return x == y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1, 0);
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            if (lca(u, v)) {
                LL ans = (LL)abs(sz[u] - sz[v]) * min(sz[u], sz[v]);
                ans += (LL)min(sz[u], sz[v]) * min(sz[u], sz[v]);
                cout << ans << endl;
            } else {
                cout << (LL)sz[u] * sz[v] << endl;
            }
        }
    }
    return 0;
}