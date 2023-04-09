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
const int N = 3 + 3e3;

int n, a[N], b[N];
LL dp[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i] - i;
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; ++i) {
        LL temp = 1e18;
        for (int j = 1; j <= n; ++j) {
            temp = min(temp, dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], temp + abs((LL)a[i] - b[j]));
        }
    }
    LL ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}