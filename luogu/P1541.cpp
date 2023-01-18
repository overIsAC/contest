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
const int N = 3 + 1e5;

int dp[42][42][42][42];
int n, a[N], b[N], m;
int c[10];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        ++c[b[i]];
    }
    memset(dp, -0x3f, sizeof(dp));
    ****dp = 0;
    for (int i = 0; i <= c[1]; ++i) {
        for (int j = 0; j <= c[2]; ++j) {
            for (int k = 0; k <= c[3]; ++k) {
                for (int q = 0; q <= c[4]; ++q) {
                    dp[i + 1][j][k][q] = max(dp[i + 1][j][k][q], dp[i][j][k][q] + a[i + 1 + j * 2 + k * 3 + q * 4 + 1]);
                    dp[i][j + 1][k][q] = max(dp[i][j + 1][k][q], dp[i][j][k][q] + a[i + (j + 1) * 2 + k * 3 + q * 4 + 1]);
                    dp[i][j][k + 1][q] = max(dp[i][j][k + 1][q], dp[i][j][k][q] + a[i + j * 2 + (k + 1) * 3 + q * 4 + 1]);
                    dp[i][j][k][q + 1] = max(dp[i][j][k][q + 1], dp[i][j][k][q] + a[i + j * 2 + k * 3 + (q + 1) * 4 + 1]);
                }
            }
        }
    }
    cout << dp[c[1]][c[2]][c[3]][c[4]] + a[1] << endl;
    return 0;
}