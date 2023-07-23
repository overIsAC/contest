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
const int N = 3 + 1e3;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    map<vector<int>, LL> dp;
    dp[vector<int>(10, 0)] = 0;
    for (auto i : a) {
        map<vector<int>, LL> ndp;
        map<int, int> mp;
        int ok = 1;
        LL j = i;
        while (i) {
            if (++mp[i % 10] > 2) {
                ok = 0;
                break;
            }
            i /= 10;
        }
        if (!ok) {
            continue;
        }
        for (auto [x, y] : dp) {
            auto v = x;
            int ok = 1;
            for (int i = 0; i < 10; ++i) {
                if (v[i] + mp[i] > 2) {
                    ok = 0;
                    break;
                }
                v[i] += mp[i];
            }
            if (ok) {
                ndp[v] = max(ndp[v], y + j);
            }
        }
        for (auto &[x, y] : ndp) {
            dp[x] = max(dp[x], y);
        }
    }
    LL ans = 0;
    for (auto &[x, y] : dp) {
        ans = max(ans, y);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}