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
const int N = 3 + 11;

int n, m;
LL k;
vector<pair<int, LL>> edge[N];
int vis[N];
LL ans = 1e18;

void dfs(int p, LL now) {
    if (p == n) {
        ans = min(ans, now);
        return;
    }

    for (int x = 1; x <= n; ++x) {
        if (!vis[x]) {
            continue;
        }
        for (auto e : edge[x]) {
            int y = e.first;
            LL w = e.second;
            if (vis[y]) {
                continue;
            }
            vis[y] = 1;
            dfs(p + 1, (w + now) % k);
            vis[y] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    while (m--) {
        int u, v;
        LL w;
        cin >> u >> v >> w;

        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    vis[1] = 1;
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}