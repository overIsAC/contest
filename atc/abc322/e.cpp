#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, k, p;
map<vector<int>, LL> dp;

int main() {
    cin >> n >> k >> p;
    dp[vector<int>(k, 0)] = 0;
    while (n--) {
        int c;
        vector<int> a(k);
        cin >> c;
        for (auto& i : a) {
            cin >> i;
        }
        decltype(dp) ndp;

        auto update = [&](vector<int>& b, LL cost) {
            if (ndp.count(b)) {
                ndp[b] = min(ndp[b], cost);
            } else {
                ndp[b] = cost;
            }
        };

        for (auto [k, v] : dp) {
            vector<int> b = k;
            update(b, v);
            for (int i = 0; i < b.size(); ++i) {
                b[i] = min(k[i] + a[i], p);
            }
            update(b, v + c);
        }

        swap(dp, ndp);
    }

    LL ans = 1e18;
    for (auto [k, v] : dp) {
        int ok = 1;
        for (auto& i : k) {
            if (i == p) {
            } else {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ans = min(ans, v);
        }
    }

    if (ans == 1e18) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}