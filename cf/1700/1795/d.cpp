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
const int N = 3 + 3e5;

int n, a[N];
LL inv[N], fac[N], invFac[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    inv[1] = 1;
    fac[0] = fac[1] = 1;
    invFac[0] = invFac[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        invFac[i] = invFac[i - 1] * inv[i] % mod;
    }

    auto c = [&](int n, int m) {
        return fac[n] * invFac[n - m] % mod * invFac[m] % mod;
    };

    LL ans = c(n / 3, n / 6);
    for (int i = 2; i < n; i += 3) {
        int b[3] = {a[i - 1], a[i], a[i + 1]};
        sort(b, b + 3);
        if (b[0] == b[2]) {
            ans *= 3;
            // 随意 * 3
        } else if (b[1] == b[2]) {
            // 确定
        } else if (b[0] == b[1]) {
            ans *= 2;
            // 随意 * 2
        } else {
            // 确定
        }
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}