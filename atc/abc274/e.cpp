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
const int N = 3 + 18;

double dp[1 << N][N];
int x[N], y[N], n, m;
double dis[N][N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dis[i][j] = sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) +
                             (double)(y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    for (int i = 0; i < 1 << N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = 4e18;
        }
    }
    for (int i = 0; i < n + m; ++i) {
        dp[1 << i][i] = sqrt((double)x[i] * x[i] + (double)y[i] * y[i]);
    }
    for (int i = 1; i < 1 << n + m; ++i) {
        int sp = 1;
        for (int j = n; j < n + m; ++j) {
            if (i >> j & 1) {
                sp *= 2;
            }
        }
        for (int j = 0; j < n + m; ++j) {
            if (!(i >> j & 1)) {
                continue;
            }
            for (int k = 0; k < n + m; ++k) {
                if (i >> k & 1) {
                    continue;
                }
                dp[i | (1 << k)][k] =
                    min(dp[i | (1 << k)][k], dp[i][j] + dis[j][k] / sp);
            }
        }
    }

    const int o = (1 << n) - 1;
    double ans = 4e18;
    for (int i = 1; i < 1 << n + m; ++i) {
        int sp = 1;
        for (int j = n; j < n + m; ++j) {
            if (i >> j & 1) {
                sp *= 2;
            }
        }
        if ((i & o) == o) {
            for (int j = 0; j < n; ++j) {
                ans = min(ans, dp[i][j] + sqrt((double)x[j] * x[j] +
                                               (double)y[j] * y[j]) /
                                              sp);
            }
        }
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}