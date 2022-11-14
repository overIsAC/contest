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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e5;

int n;
int a[N][5];
int dp[N][5][5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> a[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    ***dp = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 3; ++j) {
            for (int k = 0; k <= 3; ++k) {
                for (int q = 0; q <= 3; ++q) {
                    if (a[i][1] && q < 3) continue;
                    if (a[i][2] && q + k + 1 < 3) continue;
                    if (a[i][3] && q + k + j + 2 < 3) continue;
                    dp[i][k][q] = min(dp[i][k][q], dp[i - 1][j][k] + q);
                }
            }
        }
    }
    int ans = 1e9;
    for (int j = 0; j <= 3; ++j) {
        for (int k = 0; k <= 3; ++k) {
            ans = min(dp[n][j][k], ans);
        }
    }
    cout << ans << endl;
    return 0;
}