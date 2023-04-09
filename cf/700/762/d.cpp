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
const int N = 3 + 1e5;

int n, a[N][3];
LL dp[N][3];

LL sum(int p, int L, int R) {
    if (L > R) {
        swap(L, R);
    }
    LL ans = 0;
    for (int i = L; i <= R; ++i) {
        ans += a[p][i];
    }
    return ans;
}

int main() {
    cin >> n;
    for (int j = 0; j < 3; ++j) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i][j];
        }
    }
    memset(dp, -0x3f, sizeof(dp));
    for (int i = 0; i <= 2; ++i) {
        dp[1][i] = sum(1, 0, i);
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= 2; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + sum(i, j, k));
            }
        }
        dp[i][0] = max(dp[i][0], dp[i - 2][0] + sum(i - 1, 0, 2) + sum(i, 0, 2));
        dp[i][2] = max(dp[i][2], dp[i - 2][0] + sum(i - 1, 0, 2) + sum(i, 0, 2));
        dp[i][0] = max(dp[i][0], dp[i - 2][2] + sum(i - 1, 0, 2) + sum(i, 0, 2));
        dp[i][2] = max(dp[i][2], dp[i - 2][2] + sum(i - 1, 0, 2) + sum(i, 0, 2));
    }
    cout << dp[n][2] << endl;
    return 0;
}