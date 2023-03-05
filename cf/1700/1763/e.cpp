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
const int N = 3 + 2e5;

int dp[N], n;
int dp2[N];

int main() {
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    *dp = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * (j - 1) / 2 <= i; ++j) {
            if (dp[i] > dp[i - j * (j - 1) / 2] + j) {
                dp[i] = dp[i - j * (j - 1) / 2] + j;
                dp2[i] = dp2[i - j * (j - 1) / 2] + j * dp[i - j * (j - 1) / 2];
            } else if (dp[i] == dp[i - j * (j - 1) / 2] + j) {
                dp2[i] = max(dp2[i], dp2[i - j * (j - 1) / 2] + j * dp[i - j * (j - 1) / 2]);
            }
        }
    }
    cout << dp[n] << ' ' << dp2[n] << endl;
    return 0;
}