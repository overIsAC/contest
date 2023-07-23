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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int n, m;
LL inv[N], fac[N], facInv[N];

LL c(int n, int m) {
    return fac[n] * facInv[m] % mod * facInv[n - m] % mod;
}

LL qpow(LL q, LL n) {
    if (n < 0) {
        return 0;
    }
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
    fac[0] = 1;
    fac[1] = 1;
    facInv[0] = 1;
    facInv[1] = 1;
    for (int i = 2; i < N; ++i) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        fac[i] = fac[i - 1] * i % mod;
        facInv[i] = facInv[i - 1] * inv[i] % mod;
    }
    cin >> n >> m;
    LL ans = c(m, n - 1);

    db(ans);
    ans = ans * (n - 2) % mod;
    db(ans);
    ans = ans * qpow(2, n - 3) % mod;

    cout << ans << endl;

    return 0;
}