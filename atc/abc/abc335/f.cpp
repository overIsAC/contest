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

const int N = 3 + 2e5;
const int M = 3 + sqrt(N);

int n, a[N];
int b[M][M];
LL dp[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < M; ++j) {
            dp[i] += b[i % j][j];
        }
        dp[i] %= mod;
        if (a[i] < M) {
            b[i % a[i]][a[i]] += dp[i];
            b[i % a[i]][a[i]] %= mod;
        } else {
            for (int j = i + a[i]; j <= n; j += a[i]) {
                dp[j] += dp[i];
                dp[j] %= mod;
            }
        }
        // cout << i << ' ' << dp[i] << endl;
    }
    // cout << dp[n] << endl;
    cout << accumulate(dp, dp + n + 1, 0LL) % mod << endl;

    return 0;
}