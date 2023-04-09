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

int n, a[N][3];
LL dp[N][1 << 3][3];

int main() {
    cin >> n;
    for (int j = 0; j < 3; ++j) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i][j];
        }
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[1][1][0] = a[1][0];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 1 << 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (!(j >> k & 1)) {
                    continue;
                }
                dp[i + 1][1 << k][k] = max(dp[i + 1][1 << k][k], dp[i][j][k] + a[i + 1][k]);
                for (int q = 0; q < 3; ++q) {
                    if (abs(k - q) != 1) {
                        continue;
                    }
                    if (j >> q & 1) {
                        continue;
                    }
                    dp[i][j | (1 << q)][q] = max(dp[i][j | (1 << q)][q], dp[i][j][k] + a[i][q]);
                }
            }
        }
    }
    LL ans = -1e18;
    for (int i = 1; i < 1 << 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i >> j & 1) {
                ans = max(ans, dp[n][i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}