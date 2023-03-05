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
const int N = 3 + 1e6;

int n, k;
LL inv[N], fac[N], fac_inv[N];

LL c(int n, int m) {
    if (n < m) {
        return 0;
    }
    return fac[n] * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    inv[1] = 1;
    fac_inv[1] = 1;
    fac_inv[0] = 1;
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % mod;
    }
    cin >> n >> k;
    LL ans = 0;
    for (int i = 1; i <= k; ++i) {
        if (i + k <= n) {
            ans += qpow(3, n - 2 * i);
        }
        if (i + k <= n + 1) {
            ans += qpow(3, k - i) * qpow(3, n - k - i + 1) % mod * 1 % mod;
        }
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}