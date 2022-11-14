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
const int N = 3 + 2333;

int n, m, q;
int a[N];
int dp[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    reverse(a + 1, a + n + 1);
    memset(dp, -0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }
        dp[i][0] = max(dp[i][0], dp[i - 1][m] + a[i]);
    }
    cout << *max_element(dp[n], dp[n] + m + 2) << endl;

    return 0;
}