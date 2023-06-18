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

int n, m;
int dp[N][2];
string s[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            reverse(s[i].begin(), s[i].end());
        }
        auto calc = [&](int p, int u, int v) {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                int c = s[i][p] - '0';
                c ^= ((s[i][p - 1] - '0') != v);
                ans += c != u;
            }
            return ans;
        };
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i = 0; i < n; ++i) {
            dp[0][0] += s[i][0] != '0';
            dp[0][1] += s[i][0] != '1';
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= 1; ++j) {
                dp[i][j] = 1e9;
                for (int k = 0; k <= 1; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + calc(i, j, k));
                }
            }
        }
        cout << min(dp[m - 1][0], dp[m - 1][1]) << endl;
    }
    return 0;
}