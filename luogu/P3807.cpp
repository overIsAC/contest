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
// const int mod = 998244353;
const int N = 3 + 2e5;

LL fac[N];
int n, m, p;

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % p;
        n >>= 1;
        q = q * q % p;
    }
    return ans;
}

LL c(LL n, LL m) {
    if (n < m) {
        return 0;
    }
    return fac[n] * qpow(fac[m], p - 2) % p * qpow(fac[n - m], p - 2) % p;
}

LL lucas(LL n, LL m) {
    if (!m) {
        return 1;
    }
    return c(n % p, m % p) * lucas(n / p, m / p) % p;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        if (p == 1) {
            cout << 0 << endl;
            continue;
        }
        fac[0] = 1;
        for (int i = 1; i <= p; ++i) {
            fac[i] = fac[i - 1] * i % p;
        }
        cout << lucas(n + m, m) << endl;
    }
    return 0;
}