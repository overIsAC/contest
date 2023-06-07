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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m, k;
int a[N];
LL inv[N];

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
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 2e5; ++i) {
        inv[i] = qpow(i, mod - 2);
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        if (n > m) {
            cout << 0 << endl;
            assert(false);
        }
        LL ans = qpow(k - 1, m), cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = cnt * (m - i + 1) % mod * inv[i] % mod;
            ans = (ans + qpow(k - 1, m - i) * cnt) % mod;
        }
        ans = (qpow(k, m) - ans + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}