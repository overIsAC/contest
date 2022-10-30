#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
int a[N];
LL dp[N][2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][1] + a[i - 1] - 1, dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] + a[i] - 1, dp[i - 1][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}