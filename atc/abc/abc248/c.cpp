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
// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 55;

int n, m, k;
LL dp[N][N * N];

int main() {
    cin >> n >> m >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i * m, k); ++j) {
            for (int q = 1; q <= min(m, j); ++q) {
                dp[i][j] += dp[i - 1][j - q];
                dp[i][j] %= mod;
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += dp[n][i];
    }
    cout << ans % mod << endl;
    return 0;
}