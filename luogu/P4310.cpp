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

map<int, int> mp;
int dp[N], n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < 30; ++j) {
            if (a[i] >> j & 1) {
                dp[i] = max(dp[i], mp[j] + 1);
            }
        }
        for (int j = 0; j < 30; ++j) {
            if (a[i] >> j & 1) {
                mp[j] = max(mp[j], dp[i]);
            }
        }
        if (a[i] > 0) {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}