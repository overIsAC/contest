#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

int n, a[N];
LL pre[N];
LL b[N], t;
LL dp[N];
LL tr1[N], tr2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        t = 0;
        for (int i = 0; i <= n; ++i) {
            b[++t] = pre[i];
        }
        sort(b + 1, b + t + 1);
        t = unique(b + 1, b + t + 1) - b - 1;

        for (int i = 1; i <= t; ++i) {
            tr1[i] = -1e18;
            tr2[i] = -1e18;
        }

        map<LL, LL> mp;

        for (int i = 1; i <= n; ++i) {
            int p = lower_bound(b + 1, b + t + 1, pre[i - 1]) - b;

            if (!mp.count(pre[i - 1])) {
                mp[pre[i - 1]] = dp[i - 1];
            } else {
                mp[pre[i - 1]] = max(mp[pre[i - 1]], dp[i - 1]);
            }

            for (int j = p; j <= t; j += j & -j) {
                tr1[j] = max(tr1[j], dp[i - 1] - i + 1);
            }
            for (int j = p; j >= 1; j -= j & -j) {
                tr2[j] = max(tr2[j], dp[i - 1] + i - 1);
            }

            p = lower_bound(b + 1, b + t + 1, pre[i]) - b;
            LL dp1 = -1e18;
            for (int j = p - 1; j >= 1; j -= j & -j) {
                dp1 = max(dp1, tr1[j]);
            }
            dp1 += i;

            LL dp2 = -1e18;
            for (int j = p + 1; j <= t; j += j & -j) {
                dp2 = max(dp2, tr2[j]);
            }
            dp2 += -i;
            dp[i] = max(dp1, dp2);
            if (mp.count(pre[i])) {
                dp[i] = max(dp[i], mp[pre[i]]);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}