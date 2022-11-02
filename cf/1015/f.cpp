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
const int N = 3 + 233;

LL dp[N][N][N];
int n, m;
char s[N];
int nxt[N], p[N][2];

int main() {
    cin >> n >> s + 1;
    m = strlen(s + 1);

    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && s[j + 1] != s[i]) {
            j = nxt[j];
        }
        if (s[j + 1] == s[i]) {
            ++j;
        }
        nxt[i] = j;
    }

    for (int i = 1; i <= m; ++i) {
        int j = i;
        while (j && s[j + 1] != '(') {
            j = nxt[j];
        }
        if (s[j + 1] == '(') {
            ++j;
        }
        p[i][0] = j;

        j = i;
        while (j && s[j + 1] != ')') {
            j = nxt[j];
        }
        if (s[j + 1] == ')') {
            ++j;
        }
        p[i][1] = j;
    }

    ***dp = 1;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k < m; ++k) {
                dp[i][j][k] %= mod;
                if (s[k + 1] == '(') {
                    dp[i + 1][j + 1][k + 1] += dp[i][j][k];
                } else {
                    dp[i + 1][j + 1][p[k][0]] += dp[i][j][k];
                }
                if (j >= 1) {
                    if (s[k + 1] == ')') {
                        dp[i + 1][j - 1][k + 1] += dp[i][j][k];
                    } else {
                        dp[i + 1][j - 1][p[k][1]] += dp[i][j][k];
                    }
                }
            }
            dp[i][j][m] %= mod;
            dp[i + 1][j + 1][m] += dp[i][j][m];
            if (j >= 1) {
                dp[i + 1][j - 1][m] += dp[i][j][m];
            }
        }
    }
    cout << dp[2 * n][0][m] % mod << endl;
    return 0;
}