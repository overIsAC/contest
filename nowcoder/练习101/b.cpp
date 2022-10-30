#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e7;

int n;
LL dp[N][2];

int main() {
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            dp[i][0] += dp[i - 1][0] * ((i + 1) / 2) % mod;
            dp[i][1] += dp[i - 1][1] * ((i + 1) / 2) % mod;
            dp[i][1] += dp[i - 1][0] * ((i + 1) / 2) % mod;
            dp[i][0] += dp[i - 1][1] * ((i + 1) / 2) % mod;
        } else {
            dp[i][0] += dp[i - 1][0] * (i + 1) % mod;
            dp[i][1] += dp[i - 1][1] * (i + 1) % mod;
        }
        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    cout << dp[n][1] << endl;
    return 0;
}