#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], dp[N], pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] ^ a[i];
        }
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + 1;
            }

            if (mp.count(pre[i - 1])) {
                mp[pre[i - 1]] = min(mp[pre[i - 1]], dp[i - 1] - i);
            } else {
                mp[pre[i - 1]] = dp[i - 1] - i;
            }
            if (mp.count(pre[i])) {
                dp[i] = min(dp[i], mp[pre[i]] + i);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}