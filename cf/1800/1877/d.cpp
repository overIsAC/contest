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

set<int> st[N];
int n, a[N];
int p[N];

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
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            st[j].insert(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    sort(p + 1, p + n + 1, [](int u, int v) {
        return u[a] > v[a];
    });
    LL ans = 0;
    int m = n;
    for (int i = 1; i <= n; ++i) {
        ans += (qpow(2, st[p[i]].size()) - 1) * a[p[i]] % mod * qpow(2, m - st[p[i]].size());
        ans %= mod;
        auto t = st[p[i]];
        m -= t.size();
        for (auto &j : t) {
            for (int k = j; k <= n; k += j) {
                st[k].erase(j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}