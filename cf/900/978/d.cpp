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

int n, b[N], dp[N][3][3];

int main() {
    cin >> n;
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            dp[2][i][j] = (i != 1) + (j != 1);
        }
    }

    auto check = [&](int a, int b, int c) {
        return b * 2 == a + c;
    };

    for (int i = 3; i <= n; ++i) {
        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= 2; ++k) {
                for (int q = 0; q <= 2; ++q) {
                    if (check(b[i - 2] + j - 1, b[i - 1] + k - 1, b[i] + q - 1)) {
                        dp[i][k][q] = min(dp[i][k][q], dp[i - 1][j][k] + (q != 1));
                    }
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            ans = min(ans, dp[n][i][j]);
        }
    }
    if (ans > 1e7) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}