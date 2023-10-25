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
const int N = 3 + 1e3;

LL dp[N][N][2];
int n, m;
int a[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[1][1][0] = a[1][1];
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i][j][0] + a[i][j + 1]);
            dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][0] + a[i][j + 1]);
            dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0] + a[i + 1][j]);
        }
        for (int i = n; i >= 1; --i) {
            dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i][j][1] + a[i][j + 1]);
            dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][1] + a[i][j + 1]);
            dp[i - 1][j][1] = max(dp[i - 1][j][1], dp[i][j][1] + a[i - 1][j]);
        }
    }

    cout << max(dp[n][m][0], dp[n][m][1]) << endl;
    return 0;
}