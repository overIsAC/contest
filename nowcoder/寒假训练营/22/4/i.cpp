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
const int N = 3 + 1e3;

int n, k;
LL dp[N][N];
int a[N], b[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            LL &v = dp[i][(j + a[i]) % k];
            v = max(v, dp[i - 1][j] + b[i]);
            LL &u = dp[i][j];
            u = max(u, dp[i - 1][j]);
            LL &w = dp[i][a[i] % k];
            w = max<LL>(w, b[i]);
        }
    }
    dp[n][0] = max<LL>(dp[n][0], -1);
    cout << dp[n][0] << endl;

    return 0;
}