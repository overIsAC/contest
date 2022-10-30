#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
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
const int N = 3 + 2e5;

int n, m, a, b;
LL fac[N], inv[N], fac_inv[N];

LL c(int n, int m) { return fac[n] * fac_inv[m] % mod * fac_inv[n - m] % mod; }

int main() {
    fac[1] = fac[0] = 1;
    fac_inv[1] = fac_inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % mod;
    }

    cin >> n >> m >> a >> b;

    auto path = [&](int n, int m) { return c(n + m - 2, n - 1); };
    LL ans = 0;

    for (int i = b + 1; i <= m; ++i) {
        ans += path(n - a, i) * path(a, m - i + 1) % mod;
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}