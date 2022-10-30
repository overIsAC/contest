#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 3e3;

int n, m;
int a[N], b[N];
int dp2[N];
int dp[N][N];

void calc(int n, int m, int *a, int *b, int *dp) {
    for (int i = 1; i <= m; ++i) {
        dp[i] = -1e9;
    }
    *dp = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= b[i]; --j) {
            dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    **dp = 1;
    for (int i = 1, s; i <= n; ++i) {
        scanf("%d", &s);
        for (int i = 1; i <= s; ++i) {
            scanf("%d", a + i);
        }
        int sum = 0;
        for (int i = 1; i <= s; ++i) {
            scanf("%d", b + i);
            sum += b[i];
        }
        calc(s, sum, a, b, dp2);
        for (int j = 0; j <= sum; ++j) {
            if (dp2[j] < 0) continue;
            for (int k = 0; k <= m + 1; ++k) {
                int &v = dp[i][min(m + 1, k + dp2[j])];
                v += dp[i - 1][k];
                if (v >= mod) v -= mod;
            }
        }
    }
    cout << (dp[n][m] + dp[n][m + 1]) % mod << endl;
    return 0;
}