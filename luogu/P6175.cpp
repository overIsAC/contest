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
const int N = 3 + 123;

int d[N][N], n, m, mp[N][N];

int main() {
    memset(mp, 0x3f, sizeof(mp));
    memset(d, 0x3f, sizeof(d));
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = min(mp[v][u], w);
        d[u][v] = d[v][u] = min(d[v][u], w);
    }
    int ans = INT_MAX;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i < k; ++i) {
            for (int j = 1; j < k; ++j) {
                if (i == j) {
                    continue;
                }
                ans = min<LL>(ans, (LL)d[i][j] + mp[i][k] + mp[k][j]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    if (ans > 5e8) {
        cout << "No solution." << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}