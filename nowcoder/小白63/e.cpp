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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e6;

int n;

LL fac[N], inv[N], fac_inv[N];

LL c(int n, int m) {
    if (m == 0 || n == m) {
        return 1;
    }
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    inv[1] = 1;
    fac[0] = fac_inv[0] = fac[1] = fac_inv[1] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        fac[i] = fac[i - 1] * i % mod;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % mod;
    }
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    LL ans = 0;
    LL cnt = 1;
    for (int i = 2; i <= n; ++i) {
        ans += (n - i + 1) * cnt % mod;
        ans %= mod;
        cnt += i;
        cnt %= mod;
    }
    ans = ans * fac[n - 2] % mod * 2 % mod;
    cout << ans << endl;
    return 0;
}