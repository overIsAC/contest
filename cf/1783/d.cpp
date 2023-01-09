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
const int N = 3 + 300;
const int M = 300 * 300;

int n, a[N];
LL dp[2][M * 2 + 1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0][M] = 1;
    int sum = a[1];
    for (int i = 2; i < n; ++i) {
        int p = i & 1, q = p ^ 1;
        sum += a[i];
        for (int j = -sum; j <= sum; ++j) {
            int v = a[i] + j;
            if (v == 0) {
                (dp[q][v + M] += dp[p][j + M]) %= mod;
            } else {
                if (-sum <= v && v <= sum) {
                    (dp[q][v + M] += dp[p][j + M]) %= mod;
                }
                if (-sum <= v && v <= sum) {
                    (dp[q][-v + M] += dp[p][j + M]) %= mod;
                }
            }
            dp[p][j + M] = 0;
        }
        // for (auto &j : dp[i]) {
        //     int v = a[i] + j.first;
        //     if (v == 0) {
        //         (dp[i + 1][v] += j.second) %= mod;
        //     } else {
        //         (dp[i + 1][v] += j.second) %= mod;
        //         (dp[i + 1][-v] += j.second) %= mod;
        //     }
        // }
    }
    LL ans = 0;
    for (int i = 0; i <= 2 * M; ++i) {
        ans += dp[n & 1][i];
    }
    cout << ans % mod << endl;
    return 0;
}