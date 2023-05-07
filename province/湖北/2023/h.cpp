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
const int N = 3 + 1e6;

int du[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        ++du[u];
        ++du[v];
    }
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        ++mp[du[i]];
    }
    vector<PII> ve(mp.begin(), mp.end());
    LL ans = 0;
    auto calc = [](int x, int y) -> LL {
        return (LL)(x ^ y) * (x | y) % mod * (x & y) % mod;
    };
    for (int i = 0; i < ve.size(); ++i) {
        ans += (LL)(ve[i].second + 1) * ve[i].second / 2 % mod * calc(ve[i].first, ve[i].first) % mod;
        for (int j = i + 1; j < ve.size(); ++j) {
            ans += calc(ve[i].first, ve[j].first) * ve[i].second % mod * ve[j].second % mod;
        }
    }
    cout << ans % mod << endl;
    return 0;
}