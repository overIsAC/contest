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
const int N = 3 + 1234;

int n, k;
LL dp[N][N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        LL sum = 0;
        for (int j = 1; j <= k; ++j) {
            sum += dp[i - 1][j];
        }
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = sum - dp[i - 1][j];
        }
    }
    LL ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += dp[n][i];
    }
    cout << ans << endl;
    return 0;
}