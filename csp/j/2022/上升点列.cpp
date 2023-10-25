#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 555;

int n, k;
PII a[N];
int dp[N][N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 1;
            for (int q = 1; q < i; ++q) {
                if (a[q].second <= a[i].second && j >= (a[i].first - a[q].first) + (a[i].second - a[q].second) - 1) {
                    dp[i][j] = max(dp[i][j], dp[q][j - ((a[i].first - a[q].first) + (a[i].second - a[q].second) - 1)] + (a[i].first - a[q].first) + (a[i].second - a[q].second));
                }
            }
            ans = max(ans, dp[i][j] + k - j);
        }
    }
    cout << ans << endl;
    return 0;
}