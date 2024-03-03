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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<PII, int> dp;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];

        map<PII, int> ndp;

        ndp[{max(i - a[i] + 1, 1), i}] = 1;
        ndp[{i, min(i + a[i] - 1, n)}] = 1;

        auto update = [&](int l, int r, int w) {
            int& z = ndp[{l, r}];
            if (!z) {
                z = w;
            } else {
                z = min(z, w);
            }
        };

        for (auto& [u, v] : dp) {
            auto [l, r] = u;
            update(l, r, v);

            int L = max(i - a[i] + 1, 1), R = i;

            if (!(r < L - 1 || R < l - 1)) {
                update(min(l, L), max(r, R), v + 1);
            }
            L = i;
            R = min(i + a[i] - 1, n);

            if (!(r < L - 1 || R < l - 1)) {
                update(min(l, L), max(r, R), v + 1);
            }
        }

        swap(ndp, dp);
    }

    cout << dp[{1, n}] << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

#if 0
1
10
1 4 1 1 1 1 4 6 1 1
#endif