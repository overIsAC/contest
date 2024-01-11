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
const int N = 3 + 1e5;

int n, m;
int w[N];
double dp[1 << 16][16];
int u[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    double sum = accumulate(w, w + n, 0.0) / m;
    for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = 1e18;
        }
    }
    for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j <n; ++j) {
            if (i >> j & 1) {
                u[i] += w[j];
            }
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < 1 << n; ++i) {
        for (int j = i; j; j = i & (j - 1)) {
            for (int k = 1; k <= m; ++k) {
                dp[i][k] = min(dp[i][k],
                               dp[i ^ j][k - 1] + (u[j] - sum) * (u[j] - sum));
            }
        }
        for (int k = 1; k <= m; ++k) {
            dp[i][k] = min(dp[i][k], dp[i][k - 1] + sum * sum);
        }
    }
    double ans = dp[(1 << n) - 1][m] / m;
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}