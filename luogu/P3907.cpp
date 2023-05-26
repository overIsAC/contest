#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 50;

vector<PII> edge[N];
int n, m;
vector<tuple<int, int, int>> e;
int vis[N], xo[N];
int fa[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void dfs(int x, int fa) {
    vis[x] = 1;
    for (auto [y, w] : edge[x]) {
        if (y == fa) {
            continue;
        }
        xo[y] = xo[x] ^ w;
        dfs(y, x);
    }
}

void solve() {
    for (auto [x, y, w] : e) {
        if (xo[x] ^ xo[y] ^ w) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            edge[i].clear();
            vis[i] = 0;
        }
        e.clear();
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            if (find(u) != find(v)) {
                fa[find(u)] = find(v);
                edge[u].push_back({v, w});
                edge[v].push_back({u, w});
            } else {
                e.push_back({u, v, w});
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs(i, 0);
            }
        }
        solve();
    }
    return 0;
}