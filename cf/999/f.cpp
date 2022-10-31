#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, k;
map<int, int> mp1, mp2;
int h[N];

LL calc(int n, int m) {
    vector<vector<LL>> dp(n + 1, vector<LL>(m + 1, -1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int q = 0; q + j <= m; ++q) {
                dp[i][q + j] = max(dp[i][q + j], dp[i - 1][q] + h[j]);
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i <= m; ++i) {
        ans = max(dp[n][i], ans);
    }
    if (ans >= 0)
        return ans;
    else
        return 0;
}

int main() {
    cin >> n >> k;
    for (int i = n * k, a; i; --i) {
        cin >> a;
        ++mp1[a];
    }
    for (int i = n, a; i; --i) {
        cin >> a;
        ++mp2[a];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> h[i];
    }
    LL ans = 0;
    for (auto& i : mp2) {
        ans += calc(i.second, mp1[i.first]);
    }
    cout << ans << endl;
    return 0;
}