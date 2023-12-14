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

LL x[N], y[N];

vector<array<int, 3>> edge[N];
int n, m;
int vis[N];

void dfs(int u, LL dx, LL dy) {
    if (vis[u]) {
        return;
    }
    x[u] = dx;
    y[u] = dy;
    vis[u] = 1;
    for (auto [v, tx, ty] : edge[u]) {
        dfs(v, dx + tx, dy + ty);
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        edge[u].push_back({v, x, y});
        edge[v].push_back({u, -x, -y});
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            cout << x[i] << ' ' << y[i] << endl;
        } else {
            cout << "undecidable" << endl;
        }
    }
    return 0;
}