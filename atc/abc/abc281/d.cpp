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
const int N = 3 + 100;

int n, k, d, a[N];
LL dp[N][N][N];

int main() {
    cin >> n >> k >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int q = 0; q < d; ++q) {
                dp[i + 1][j][q] = max(dp[i + 1][j][q], dp[i][j][q]);
                dp[i + 1][j + 1][(q + a[i + 1]) % d] = max(dp[i + 1][j + 1][(q + a[i + 1]) % d], dp[i][j][q] + a[i + 1]);
            }
        }
    }
    LL ans = max<LL>(dp[n][k][0], -1);
    cout << ans << endl;
    return 0;
}