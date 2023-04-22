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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        if (n == 1) {
            cout << a[0] << endl;
            continue;
        }
        vector<vector<int>> dp(n, vector<int>(2, 1e9));
        dp[0][0] = a[0];
        dp[1][0] = a[0] + a[1];
        dp[1][1] = a[0];
        for (int i = 2; i < n; ++i) {
            dp[i][0] = min(dp[i][0], dp[i - 2][1] + a[i] + a[i - 1]);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i]);
            dp[i][1] = min(dp[i][1], dp[i - 2][0]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    return 0;
}