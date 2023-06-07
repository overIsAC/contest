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
const int N = 3 + 1e6;

int n, m, k;

LL dp[1000][1000];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] += dp[i - 1][j] * (k - 1);
                if (j) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
            dp[i][n] += dp[i - 1][n - 1];
            dp[i][n] += dp[i - 1][n] * k;
        }
        for (int i=  0; i <= m; ++i) {
            for (int j= 0; j <= n; ++j) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        // cout << dp[m][n] << endl;
    }
    return 0;
}