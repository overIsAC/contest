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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2333;

int n, k;
LL dp[N][N][2][2];

int main() {
    cin >> n >> k;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            dp[1][i == j ? 1 : 2][i][j] = 1;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            for (int q = 0; q <= 1; ++q) {
                for (int w = 0; w <= 1; ++w) {
                    for (int u = 0; u <= 1; ++u) {
                        for (int v = 0; v <= 1; ++v) {
                            int c = j + 2;
                            if (u == v) {
                                --c;
                                if (u == q) {
                                    --c;
                                } else if (v == w) {
                                    --c;
                                }
                            } else {
                                if (u == q) {
                                    --c;
                                }
                                if (v == w) {
                                    --c;
                                }
                            }
                            dp[i + 1][c][u][v] += dp[i][j][q][w];
                            dp[i + 1][c][u][v] %= mod;
                        }
                    }
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            ans += dp[n][k][i][j];
        }
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}