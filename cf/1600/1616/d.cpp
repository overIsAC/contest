#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, x, a[N];
int dp[N][2];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cin >> x;
        for (int i = 1; i <= n; ++i) {
            a[i] -= x;
            dp[i][0] = dp[i][1] = 0;
        }
        auto check = [](int l, int r, int p) {
            int u = 0;
            for (int i = 0; i < 3 && l - i >= 1; ++i) {
                int v = 0;
                u += a[l - i];
                for (int j = 0; j < p; ++j) {
                    v += a[r - j];
                    
                }
            }
            return true;
        };
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = dp[i - 1][0];
            dp[i][0] = dp[i - 1][1];
            if (i >= 1 && a[i] + a[i - 1] >= 0) {
                dp[i][1] = max(dp[i - 2][0] + 2, dp[i][1]);
            }
            if (i >= 2 && a[i] + a[i - 1] + a[i - 2] >= 0 &&
                a[i] + a[i - 1] >= 0 && a[i - 1] + a[i - 2] >= 0) {
                dp[i][1] = max(dp[i][1], dp[i - 3][0]) + 3;
            }
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}