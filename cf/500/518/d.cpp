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
const int N = 3 + 2222;

int n, m;
double p;
double dp[N][N];

int main() {
    cin >> m >> p >> n;
    dp[0][m] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i + 1][j - 1] += p * dp[i][j];
            dp[i + 1][j] += (1 - p) * dp[i][j];
        }
        dp[i + 1][0] += dp[i][0];
    }
    double ans = 0;
    for (int i = 0; i <= m; ++i) {
        ans += dp[n][i] * (m - i);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}