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

LL qpow(LL q, LL n, LL mod) {
    LL ans = 1 % mod;
    while (n) {
        if (n & 1)
            ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int phi(int n) {
    LL ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ans = ans * (i - 1) / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        ans = ans * (n - 1) / n;
    }
    return ans;
}

int solve(int p) {
    if (p == 1) {
        return 0;
    }
    int t = phi(p);
    return qpow(2, solve(t) + t, p);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int p;
        cin >> p;
        cout << solve(p) << endl;
    }
    return 0;
}