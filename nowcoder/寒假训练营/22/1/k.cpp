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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
char s[N];
int dp[N][4][4];

int main() {
    cin >> n;
    cin >> s + 1;
    memset(dp, -0x3f, sizeof(dp));
    memset(dp[2], 0, sizeof(dp[2]));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 0) ++dp[2][i][j];
            if (j == 0) ++dp[2][i][j];
        }
    }
    for (int i = 3; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int q = 0; q < 3; ++q) {
                    int g = 0, r = 0;
                    if (j == 0) ++g;
                    if (k == 0) ++g;
                    if (q == 0) ++g;
                    if (j == 1) ++r;
                    if (k == 1) ++r;
                    if (q == 1) ++r;
                    if (s[i] == 'R') {
                        if (r <= g) {
                            continue;
                        }
                    }
                    if (s[i] == 'G') {
                        if (g <= r) {
                            continue;
                        }
                    }
                    if (s[i] == 'B') {
                        if (g != r) {
                            continue;
                        }
                    }
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][q] + (j == 0));
                }
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}