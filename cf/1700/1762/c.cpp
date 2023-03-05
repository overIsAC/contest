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
const int N = 3 + 2e5;

int n;
char s[N];

LL inv[N], fac[N], fac_inv[N];

LL c(LL n, LL m) { return fac[n] * fac_inv[m] % mod * fac_inv[n - m]; }

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
    fac[0] = fac[1] = 1;
    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % mod;
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s + 1;
        LL ans = 1;
        int u = s[1] == '1';
        int v = s[1] == '0';
        int z = 0;
        LL temp = 1;
        for (int i = 2; i <= n; ++i) {
            ++z;
            if (s[i] == '1') {
                ++u;
                if (u <= v) {
                    if (z <= v - u) {
                        break;
                    }
                    temp = temp * c(z, v + 1 - u) % mod;
                    z -= v - u + 1;
                    u = v + 1;
                }
            } else {
                ++v;
                if (v <= u) {
                    if (z <= u - v) {
                        break;
                    }
                    temp = temp * c(z, u + 1 - v) % mod;
                    z -= u - v + 1;
                    v = u + 1;
                }
            }
            ans += temp * qpow(2, z);
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}