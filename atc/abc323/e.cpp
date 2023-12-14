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

int n, x, t[N];
LL dp[N];

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
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    const int inv = qpow(n, mod - 2);

    LL ans = 0;
    dp[0] = 1;

    for (int i = 0; i <= x; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i + t[j] > x) {
                if (j == 1) {
                    ans += dp[i] * inv;
                    ans %= mod;
                }
                continue;
            }
            dp[i + t[j]] += dp[i] * inv;
            dp[i + t[j]] %= mod;
        }
    }

    cout << ans % mod << endl;

    return 0;
}