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
const int N = 3 + 400;

int n, c, a[N], b[N];
LL dp[N][N];
LL pre[N][N];

LL calc(int a, int L, int R) {
    return (pre[a][R] - pre[a][L - 1] + mod) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    for (int j = 1; j <= 400; ++j) {
        pre[0][j] = 1;
        for (int i = 1; i <= c; ++i) {
            pre[i][j] = pre[i - 1][j] * j % mod;
        }
    }
    for (int i = 0; i <= c; ++i) {
        for (int j = 1; j <= 400; ++j) {
            pre[i][j] = (pre[i][j] + pre[i][j - 1]) % mod;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= c; ++j) {
            for (int k = j; k <= c; ++k) {
                dp[i][k] =
                    (dp[i][k] + dp[i - 1][j] * calc(k - j, a[i], b[i])) % mod;
            }
        }
    }
    LL ans = dp[n][c];
    cout << (ans % mod + mod) % mod << endl;
    return 0;
}