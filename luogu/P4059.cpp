#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3000;

int n, m;
char s[N], t[N];
int a, b;

int d[11][11];
map<char, int> id;
int dp[N][N][2][2];
int pre1[N][N], pre2[N][N];

int main() {
    id['A'] = 1;
    id['T'] = 2;
    id['G'] = 3;
    id['C'] = 4;
    cin >> s + 1 >> t + 1;
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cin >> d[i][j];
        }
    }
    cin >> a >> b;

    memset(dp, -0x3f, sizeof(dp));
    memset(pre1, -0x3f, sizeof(pre1));
    memset(pre2, -0x3f, sizeof(pre2));

    dp[0][0][1][1] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i][0][1][0] = -a - b * (i - 1);
    }
    for (int i = 1; i <= m; ++i) {
        dp[0][i][0][1] = -a - b * (i - 1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j][1][1] = max({dp[i - 1][j - 1][0][1], dp[i - 1][j - 1][1][0], dp[i - 1][j - 1][1][1]}) + d[id[s[i]]][id[t[j]]];

            // bf
            // for (int k = 1; i - k >= 0; ++k) {
            //     int w = -a - b * (k - 1);
            //     dp[i][j][0][1] = max(dp[i][j][0][1], dp[i - k][j][1][1] + w);
            //     dp[i][j][0][1] = max(dp[i][j][0][1], dp[i - k][j][1][0] + w);
            // }
            // for (int k = 1; j - k >= 0; ++k) {
            //     int w = -a - b * (k - 1);
            //     dp[i][j][1][0] = max(dp[i][j][1][0], dp[i][j - k][1][1] + w);
            //     dp[i][j][1][0] = max(dp[i][j][1][0], dp[i][j - k][0][1] + w);
            // }
            
            pre1[i][j] = max(pre1[i - 1][j] - b, dp[i - 1][j][1][1] - a);
            pre2[i][j] = max(pre2[i][j - 1] - b, dp[i][j - 1][1][1] - a);
            dp[i][j][0][1] = pre1[i][j];
            dp[i][j][1][0] = pre2[i][j];
        }
    }
    int ans = -1e9;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            ans = max(ans, dp[n][m][i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}