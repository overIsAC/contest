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
const int N = 3 + 111;

int n, m, d[N][N], vis[N];
int dp[1 << 11][11];

int main() {
    cin >> n >> m;
    memset(d, -0x3f, sizeof(d));
    while (m--) {
        int u, v, w;
        cin >> u >> v  >> w;
        --u;
        --v;
        d[u][v] = d[v][u] = max(d[v][u], w);
    }
    memset(dp, -0x3f, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) {
                for (int k = 0; k < n; ++k) {
                    if (!(i >> k & 1)) {
                        auto& v = dp[i | (1 << k)][k];
                        v = max(v, dp[i][j] + d[j][k]);
                        ans = max(ans, v);
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}