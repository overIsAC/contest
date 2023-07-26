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
const int N = 3 + 3333;

int n, k;
char s[N];
int dp[N][N];

int main() {
    cin >> n >> k;
    cin >> s + 1;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            if (i - 2 >= 1) {
                int w = 0;
                w += s[i - 2] != 'a';
                w += s[i - 1] != 'w';
                w += s[i] != 'a';
                dp[i][j] = min(dp[i][j], dp[i - 3][j - 1] + w);
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}