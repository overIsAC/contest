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
const int N = 3 + 2e5;

int fa[N], sz[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

void solve() {
    int n, s;
    cin >> n >> s;
    vector<array<int, 3>> e(n - 1);
    for (auto &[u, v, w] : e) {
        cin >> u >> v >> w;
    }
    sort(e.begin(), e.end(), [&](array<int, 3> &u, array<int, 3> &v) {
        return u[2] < v[2];
    });
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
    LL ans = 1;
    for (auto &[u, v, w] : e) {
        LL c = (LL)sz[find(u)] * sz[find(v)] - 1;
        ans *= qpow(s - w + 1, c);
        ans %= mod;
        sz[find(v)] += sz[find(u)];
        fa[find(u)] = find(v);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}