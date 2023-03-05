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
const int N = 3 + 5000;

int n, k, a[N], cold[N], hot[N];
LL dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= k; ++i) {
            cin >> cold[i];
        }
        for (int i = 1; i <= k; ++i) {
            cin >> hot[i];
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = 1e18;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (a[i] == a[i - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + hot[a[i]]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + cold[a[i]]);
                }
                if (j == a[i]) {
                    dp[i][a[i - 1]] = min(dp[i][a[i - 1]], dp[i - 1][j] + hot[a[i]]);
                } else {
                    dp[i][a[i - 1]] = min(dp[i][a[i - 1]], dp[i - 1][j] + cold[a[i]]);
                }
            }
        }
        LL ans = 1e18;
        for (int i = 0; i <= k; ++i) {
            ans = min(dp[n][i], ans);
        }
        cout << ans << endl;
    }
    return 0;
}