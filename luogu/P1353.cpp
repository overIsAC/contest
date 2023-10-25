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
const int N = 3 + 1e4;

int n, d[N], m;
int dp[N][555];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + d[i]);
        }
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        for (int j = 1; j <= m && i >= j; ++j) {
            dp[i][0] = max(dp[i][0], dp[i - j][j]);
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}