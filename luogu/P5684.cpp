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
const int N = 3 + 1e5;

LL fac[N];

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int calc(int n, string s) {
    map<char, int> mp;
    for (auto& i : s) {
        ++mp[i];
    }
    int cnt = 0;
    LL ans = 1;
    for (auto& i : mp) {
        if (i.second % 2) {
            ++cnt;
            ans *= i.second;
            ans %= mod;
            --i.second;
            --n;
        }
    }
    if (cnt >= 2) {
        return 0;
    }
    for (auto& [u, v] : mp) {
        for (int i = 2; i <= v; i += 2) {
            ans *= i * (i - 1);
            ans %= mod;
        }
        ans *= fac[n / 2] * qpow(fac[v / 2], mod - 2) % mod * qpow(fac[n / 2 - v / 2], mod - 2) % mod;
        ans %= mod;
        n -= v;
    }
    return ans;
}

int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }

    LL ans = fac[n];
    ans -= calc(n, s);
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;

    return 0;
}