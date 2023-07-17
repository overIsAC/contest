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
const int N = 3 + 555;

int n, l, k, d[N], a[N];
LL dp[N][N];

int main() {
    cin >> n >> l >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    d[++n] = l;
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int q = 0; q <= k && q + j - i - 1 <= k; ++q) {
                dp[j][q + j - i - 1] = min(dp[j][q + j - i - 1], dp[i][q] + a[i] * (d[j] - d[i]));
            }
        }
    }
    LL ans = 1e18;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}