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
const int N = 3 + 2e3;

int n, m, a[N];
int dp[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            for (int j = max(i - m, 0); j <= i + m - 1; ++j) {
                dp[min(i + m - 1, n)] = min(dp[min(i + m - 1, n)], dp[j] + 1);
            }
        }
    }
    if (dp[n] > n) {
        dp[n] = -1;
    }
    cout << dp[n] << endl;
    return 0;
}