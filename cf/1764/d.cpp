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
const int N = 3 + 1e5;

LL fac[N];

LL qpow(LL q, LL n, int mod) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    int n, p;
    cin >> n >> p;

    *fac = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % p;
    }

    auto check = [&](int i, int j) {
        vector<int> a = {0, i, j};
        for (int i = 0; i < 3; ++i) {
            if ((a[(i + 1) % 3] - a[i] + n) % n > n / 2) {
                return false;
            }
        }
        return true;
    };

    LL ans = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (check(i, j)) {
                if (n % 2 == 0 && (i - j + n) % n == n / 2) {
                    continue;
                }
                ans = (ans + fac[n - 3]) % p;
            }
        }
    }
    ans = ans * n % p;
    db(ans);
    if (n % 2 == 0) {
        ans += n * fac[n - 2] % p;
    }
    ans %= p;
    cout << ans << endl;
    return 0;
}