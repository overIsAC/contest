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
const int N = 3 + 15;

int n;
double x[N], y[N];
double ans = 1e18;
double d[N][N];
double dp[1 << N][N];

double calcDist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            d[i][j] = calcDist(x[i], y[i], x[j], y[j]);
        }
    }

    for (int i = 0; i < 1 << n + 1; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = 1e9;
        }
    }
    dp[1][0] = 0;
    for (int i = 1; i < 1 << n + 1; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i >> j & 1) {
                for (int k = 0; k <= n; ++k) {
                    dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + d[j][k]);
                }
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        ans = min(ans, dp[(1 << (n + 1)) - 1][i]);
    }

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}