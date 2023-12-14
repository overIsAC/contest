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

int n, dp[N];
char s[N];
const string t = "ABXY";

int calc(char q, char w, char e, char r) {
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (s[i - 1] == q && s[i] == w) {
            dp[i] = min(dp[i], dp[i - 2] + 1);
        }
        if (s[i - 1] == e && s[i] == r) {
            dp[i] = min(dp[i], dp[i - 2] + 1);
        }
    }
    return dp[n];
}

int main() {
    cin >> n;
    cin >> s + 1;

    int ans = n;
    for (auto& i : t) {
        for (auto& j : t) {
            for (auto& q : t) {
                for (auto& w : t) {
                    ans = min(ans, calc(i, j, q, w));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}