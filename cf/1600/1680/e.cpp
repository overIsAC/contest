#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 2e5;

int n;
char a[N], b[N];
int dp[N][4];
// 0 都没有
// 1 上
// 2 下
// 3 都有

void solve() {
    int l = n, r = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == '*' || b[i] == '*') {
            l = min(l, i);
            r = max(r, i);
        }
        memset(dp[i], 0x3f, sizeof(dp[i]));
    }
    memset(dp[l - 1], 0, sizeof(dp[0]));
    if (a[l] == '*' && b[l] == '*') {
        dp[l][3] = 0;
        dp[l][1] = 1;
        dp[l][2] = 1;
    } else if (a[l] == '*') {
        dp[l][1] = 0;
        dp[l][2] = 1;
    } else if (b[l] == '*') {
        dp[l][2] = 0;
        dp[l][1] = 1;
    }
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] == '*' && b[i] == '*') {
            dp[i][3] =
                min({dp[i - 1][3] + 2, dp[i - 1][1] + 1, dp[i - 1][2] + 1});
            dp[i][1] =
                min({dp[i - 1][1] + 2, dp[i - 1][2] + 2, dp[i - 1][3] + 3});
            dp[i][2] =
                min({dp[i - 1][1] + 2, dp[i - 1][2] + 2, dp[i - 1][3] + 3});
        } else if (a[i] == '*') {
            dp[i][1] =
                min({dp[i - 1][1] + 1, dp[i - 1][2] + 2, dp[i - 1][3] + 2});
            dp[i][2] =
                min({dp[i - 1][1] + 2, dp[i - 1][2] + 2, dp[i - 1][3] + 3});
            dp[i][3] =
                min({dp[i - 1][3] + 2, dp[i - 1][2] + 1, dp[i - 1][1] + 2});
        } else if (b[i] == '*') {
            dp[i][1] =
                min({dp[i - 1][1] + 2, dp[i - 1][2] + 2, dp[i - 1][3] + 3});
            dp[i][2] =
                min({dp[i - 1][2] + 1, dp[i - 1][2] + 1, dp[i - 1][3] + 2});
            dp[i][3] =
                min({dp[i - 1][3] + 2, dp[i - 1][2] + 1, dp[i - 1][1] + 1});
        } else {
            for (int j = 1; j <= 3; ++j) dp[i][j] = dp[i - 1][j] + 1;
            ++dp[i][3];
        }
    }

    // for (int i = l; i <= r; ++i) {
    //     cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2]
    //          << ' ' << dp[i][3] << endl;
    // }

    if (a[r] == '*' && b[r] == '*') {
        cout << dp[r][3] + 1 << endl;
    } else if (a[r] == '*') {
        cout << dp[r][1] << endl;
    } else if (b[r] == '*') {
        cout << dp[r][2] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a + 1 >> b + 1;
        solve();
    }
    return 0;
}