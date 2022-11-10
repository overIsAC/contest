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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e3;

LL dp[N][N];
int n, m, k;

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    cin >> n >> m >> k;
    dp[0][0] = 1;
    const LL inv_m = qpow(m, mod - 2);
    for (int i = 0; i < k; ++i) {
        dp[i + 1][n] += dp[i][n];
        for (int j = 0; j < n; ++j) {
            dp[i][j] %= mod;
            for (int q = 1; q <= m; ++q) {
                if (j + q > n) {
                    dp[i + 1][n - (j + q - n)] += dp[i][j] * inv_m % mod;
                } else {
                    dp[i + 1][j + q] += dp[i][j] * inv_m % mod;
                }
            }
        }
    }
    cout << dp[k][n] % mod << endl;
    return 0;
}