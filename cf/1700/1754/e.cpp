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
const int N = 3 + 1e5;

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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        auto b = a;
        sort(b.begin(), b.end());
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += a[i] != b[i];
        }
        cnt /= 2;
        if (!cnt) {
            cout << 0 << endl;
            continue;
        }
        LL ans = 0;
        LL x = (LL)n * (n - 1) / 2 % mod;
        for (int i = 1; i <= cnt; ++i) {
            ans = ans * i % mod * i % mod + x;
            ans %= mod;
            ans = qpow((LL)i * i  % mod, mod - 2) * ans % mod;
        }
        ans = (ans + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}