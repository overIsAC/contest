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
const int N = 3 + 2022 * 2;

int n, a[N];
LL dp[N][N];
int f[1000005];
LL fac[N];
LL facInv[N];

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
    f[1] = 1;
    for (int i = 2; i < 1000005; ++i) {
        if (!f[i]) {
            for (int j = i + i; j < 1000005; j += i) {
                f[j] = 1;
            }
        }
    }
    fac[0] = 1;
    facInv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        facInv[i] = qpow(fac[i], mod - 2);
    }
    cin >> n;
    for (int i = 1; i <= n * 2; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    **dp = 1;
    for (int i = 1; i <= n * 2; ++i) {
        ++mp[a[i]];
    }
    map<int, LL> u, v;
    u[0] = fac[n];
    // cout << u[0] << endl;
    for (auto &i : mp) {
        for (auto &j : u) {
            v[j.first] = (v[j.first] + j.second * facInv[i.second]) % mod;
            if (!f[i.first] && j.first + 1 <= n) {
                v[j.first + 1] = (v[j.first + 1] + j.second * facInv[i.second - 1]) % mod;
            }
        }
        swap(u, v);
        // cout << "-----------" << i.first << ' ' << i.second << endl;
        // for (auto &j : u) {
        //     cout << j.first << ' ' << j.second << endl;
        // }
        // cout << endl;
        // cout << endl;
        v.clear();
    }
    cout << u[n] << endl;
    return 0;
}