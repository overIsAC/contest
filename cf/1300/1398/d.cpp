#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 200;

int r[N], g[N], b[N], R, G, B;
LL dp[N][N][N];

int main() {
    cin >> R >> G >> B;
    for (int i = 1; i <= R; ++i) {
        cin >> r[i];
    }
    for (int i = 1; i <= G; ++i) {
        cin >> g[i];
    }
    for (int i = 1; i <= B; ++i) {
        cin >> b[i];
    }
    sort(r + 1, r + R + 1, greater<int>());
    sort(g + 1, g + G + 1, greater<int>());
    sort(b + 1, b + B + 1, greater<int>());
    memset(dp, -0x3f, sizeof(dp));
    ***dp = 0;
    LL ans = 0;
    for (int i = 0; i <= R; ++i) {
        for (int j = 0; j <= G; ++j) {
            for (int k = 0; k <= B; ++k) {
                if (i >= 1 && j >= 1) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i] * g[j]);
                }
                if (i >= 1 && k >= 1) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i] * b[k]);
                }
                if (j >= 1 && k >= 1) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j] * b[k]);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}