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

const int mod = 7 + 1e8;
// const int mod = 998244353;
const int N = 3 + 1e4;

char s[N];
int dp[N][3][3];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);

        for (int i = 1; i <= n; ++i) {
            s[i] -= '0';
        }

        if (n == 1) {
            int ans = 0;
            if (s[1] == 1) {
                ans = 2;
            } else if (s[1] == 0 || s[1] == 2) {
                ans = 1;
            }
            printf("%d\n", ans);
            continue;
        }

        for (int i = 1; i <= n; ++i) {
            memset(dp[i], 0, sizeof(dp[i]));
        }

        for (int i = 0; i <= 2; ++i) {
            for (int j = 0; j <= 2; ++j) {
                if (s[1] != i + j) continue;
                int u = 1, v = 1;
                if (i == 1) u = 2;
                if (j == 1) v = 2;
                dp[2][i][j] += v * u;
            }
        }

        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j <= 2; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    for (int q = 0; q <= 2; ++q) {
                        if (j + k + q != s[i - 1]) continue;
                        dp[i][j][k] += dp[i - 1][k][q];
                        if (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
                        if (j == 1) {
                            dp[i][j][k] += dp[i - 1][k][q];
                            if (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
                        }
                    }
                }
            }
        }

        LL ans = 0;
        for (int i = 0; i <= 2; ++i) {
            for (int j = 0; j <= 2; ++j) {
                if (s[n] == i + j) {
                    ans += dp[n][i][j];
                }
            }
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}