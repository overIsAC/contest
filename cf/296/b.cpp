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
char s[N], t[N];
LL dp[N][4];

int main() {
    cin >> n;
    cin >> s + 1;
    cin >> t + 1;
    auto get = [](int x, int y) {
        if (x < y) return 1;
        if (x > y) return 2;
        return 0;
    };
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '?' && t[i] == '?') {
            for (int j = '0'; j <= '9'; ++j) {
                for (int k = '0'; k <= '9'; ++k) {
                    int v = get(j, k);
                    dp[i][0 | v] += dp[i - 1][0];
                    dp[i][1 | v] += dp[i - 1][1];
                    dp[i][2 | v] += dp[i - 1][2];
                    dp[i][3 | v] += dp[i - 1][3];
                }
            }
        } else if (s[i] == '?') {
            for (int j = '0'; j <= '9'; ++j) {
                int v = get(j, t[i]);
                dp[i][0 | v] += dp[i - 1][0];
                dp[i][1 | v] += dp[i - 1][1];
                dp[i][2 | v] += dp[i - 1][2];
                dp[i][3 | v] += dp[i - 1][3];
            }
        } else if (t[i] == '?') {
            for (int j = '0'; j <= '9'; ++j) {
                int v = get(s[i], j);
                dp[i][0 | v] += dp[i - 1][0];
                dp[i][1 | v] += dp[i - 1][1];
                dp[i][2 | v] += dp[i - 1][2];
                dp[i][3 | v] += dp[i - 1][3];
            }
        } else {
            int v = get(s[i], t[i]);
            dp[i][0 | v] += dp[i - 1][0];
            dp[i][1 | v] += dp[i - 1][1];
            dp[i][2 | v] += dp[i - 1][2];
            dp[i][3 | v] += dp[i - 1][3];
        }
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i][2] %= mod;
        dp[i][3] %= mod;
    }
    cout << dp[n][3] << endl;
    return 0;
}