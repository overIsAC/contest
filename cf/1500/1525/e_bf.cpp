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
const int N = 3 + 5555;

int n, m;
vector<vector<int>> a;
map<vector<int>, int> mp;
LL fac[N];

int dfs(vector<int> b) {
    int p = n - b.size() + 1;
    if (p == n) {
        return b[0] <= n;
    }
    if (mp.count(b)) {
        return mp[b];
    }
    int last = 0, ans = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] <= p) {
            last = fac[n - p];
            ans = (ans + last) % mod;
            continue;
        }
        if (i && b[i] == b[i - 1]) {
            ans = (ans + last) % mod;
            continue;
        }
        auto c = b;
        c.erase(c.begin() + i);
        last = dfs(c);
        ans = (ans + last) % mod;
    }
    return mp[b] = ans;
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

int main() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (auto &i : a) {
        i.resize(m);
        for (auto &j : i) {
            cin >> j;
        }
    }
    LL ans = 0;
    for (int i = 0; i < m; ++i) {
        vector<int> b;
        for (int j = 0; j < n; ++j) {
            b.push_back(a[j][i]);
        }
        sort(b.begin(), b.end());
        ans += dfs(b);
    }
    for (int i = 1; i <= n; ++i) {
        ans = ans * qpow(i, mod - 2) % mod;
    }
    cout << ans << endl;
    return 0;
}
