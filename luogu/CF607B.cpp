#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 555;

int n, a[N];
int dp[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
        if (a[i] == a[i + 1]) {
            dp[i][i + 1] = 1;
        } else {
            dp[i][i + 1] = 2;
        }
    }
    for (int len = 3; len <= n; ++len) {
        for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
            if (a[l] == a[r]) {
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
            }
            for (int i = l; i < r; ++i) {
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
            }
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}