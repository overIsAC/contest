#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e5;

int n;
string s[N];
map<string, int> mp;
int a[2];
LL fac[N * 2], inv[N * 2], fac_inv[N];

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
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        ++mp[s[i]];
        if (s[i][0] == 'W') ++a[0];
        if (s[i][0] == 'B') ++a[1];
        if (s[i][1] == 'W') ++a[0];
        if (s[i][1] == 'B') ++a[1];
    }
    fac[1] = fac[0] = 1;
    inv[1] = 1;
    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i <= n * 2; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        fac_inv[i] = fac_inv[i - 1] * inv[i] % mod;
    }
    if (a[0] > n || a[1] > n) {
        cout << 0 << endl;
        return 0;
    }
    LL ans = 0;

    if (mp.count("WW") || mp.count("BB")) {
        ans += fac[2 * n - a[0] - a[1]] * fac_inv[n - a[0]] % mod *
               fac_inv[n - a[1]] % mod;
    } else {
        // WB
        if (!mp.count("BW") && !mp.count("B?") && !mp.count("?W")) {
            ++ans;
        }
        // BW
        if (!mp.count("WB") && !mp.count("W?") && !mp.count("?B")) {
            ++ans;
        }
        ans += fac[2 * n - a[0] - a[1]] * fac_inv[n - a[0]] % mod *
               fac_inv[n - a[1]] % mod;
        ans -= qpow(2, mp["??"]);
    }
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;
    return 0;
}