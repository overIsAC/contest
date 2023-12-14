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

const int mod = 1e4;
const int N = 3 + 1e3;

int n, k;
LL dp[N][N];

int main() {
    cin >> n >> k;
    for (int i = 0; i <= k; ++i) {
        dp[1][i] = 1;
    }

#if 0
0 1

0
1 2
1
2 1

0
1 2 3
1
1 3 2
2 1 3
3 1 2

#endif
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j - (i - 1) - 1 >= 0) {
                dp[i][j] = dp[i - 1][j] - dp[i - 1][j - (i - 1) - 1];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            if (j) {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= mod;
        }
    }
    int ans = dp[n][k];
    if (k >= 1) {
        ans -= dp[n][k - 1];
        ans %= mod;
    }
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}