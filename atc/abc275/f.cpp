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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3333;

int n, m, dp[N][N][2], a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0][0] = 1;
    dp[1][a[1]][1] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
            if (j >= a[i]) {
                dp[i][j][1] =
                    min(dp[i - 1][j - a[i]][0], dp[i - 1][j - a[i]][1]);
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        int v = min(dp[n][i][0], dp[n][i][1]);
        if (v >= 114514) {
            cout << -1 << endl;
        } else {
            cout << v << endl;
        }
    }
    return 0;
}