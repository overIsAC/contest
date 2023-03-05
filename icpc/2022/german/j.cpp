#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 1e5;

char s[N];
int dp[N][4];
map<char, int> mp;

int main() {
    cin >> s + 1;
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    mp['h'] = 0;
    mp['d'] = 1;
    mp['c'] = 2;
    mp['s'] = 3;
    vector<int> a = {0, 1, 2, 3};
    int n = strlen(s + 1);
    int ans = 0;
    do {
        for (int i = 1; i <= n; ++i) {
            memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
            int v = mp[s[i]];
            dp[i][a[v]] = max(dp[i][a[v]], dp[i - 1][a[v]] + 1);
            if (a[v]) {
                dp[i][a[v]] = max(dp[i][a[v]], dp[i - 1][a[v] - 1] + 1);
            }
        }
        for (int i = 0; i < 4; ++i) {
            ans = max(ans, dp[n][i]);
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << n - ans << endl;
    return 0;
}