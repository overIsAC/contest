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
const int N = 3 + 5e5;

int n, k;
char s[N];
int dp[N][26];
int pre[N][26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    cin >> s + 1;
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; ++i) {
        PII v1 = {n * 2, 0}, v2{n * 2, 0};
        for (int j = 0; j < k; ++j) {
            if (v1 >= (PII){dp[i - 1][j], j}) {
                v2 = v1;
                v1 = (PII){dp[i - 1][j], j};
            } else {
                v2 = min(v2, (PII){dp[i - 1][j], j});
            }
        }
        for (int j = 0; j < k; ++j) {
            if (v1.second != j) {
                dp[i][j] = min(dp[i][j], v1.first + (j != s[i] - 'A'));
                if (dp[i][j] == v1.first + (j != s[i] - 'A')) {
                    pre[i][j] = v1.second;
                }
            }
            if (v2.second != j) {
                dp[i][j] = min(dp[i][j], v2.first + (j != s[i] - 'A'));
                if (dp[i][j] == v2.first + (j != s[i] - 'A')) {
                    pre[i][j] = v2.second;
                }
            }
        }
    }
    int ans = 2 * n;
    for (int i = 0; i < k; ++i) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;

    string t;
    int p = 0;
    for (int i = 0; i < k; ++i) {
        if (ans == dp[n][i]) {
            p = i;
        }
    }
    t += p + 'A';
    for (int i = n; i > 1; --i) {
        t += pre[i][p] + 'A';
        p = pre[i][p];
    }
    reverse(t.begin(), t.end());
    cout << t << endl;

    return 0;
}