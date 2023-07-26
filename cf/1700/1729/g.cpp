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
const int N = 3 + 500;

char s[N], t[N];
int h[N][N];
int p[N];

int dp[N];
LL cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1 >> t + 1;
        int n = strlen(s + 1), m = strlen(t + 1);
        memset(h, 0, sizeof(h));
        memset(p, 0, sizeof(p));
        for (int i = 1, j = i + m - 1; j <= n; ++i, ++j) {
            if (strncmp(s + i, t + 1, m) == 0) {
                h[i][j] = 1;
                p[j] = 1;
            }
        }
        for (int len = m + 1; len <= n; ++len) {
            for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
                if (h[i + 1][j] || h[i][j - 1]) {
                    h[i][j] = 1;
                }
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        dp[0] = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + m; j <= n; ++j) {
                if (p[j]) {
                    if (h[i + 1][j - m]) {
                        break;
                    }
                    if (dp[j] > dp[i] + 1) {
                        dp[j] = dp[i] + 1;
                        cnt[j] = cnt[i];
                    } else if (dp[j] == dp[i] + 1) {
                        cnt[j] += cnt[i];
                    }
                    cnt[j] %= mod;
                }
            }
        }
        int p = 1e9;
        LL ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (!h[i + 1][n]) {
                if (p > dp[i]) {
                    p = dp[i];
                    ans = cnt[i];
                } else if (p == dp[i]) {
                    p = dp[i];
                    ans += cnt[i];
                }
            }
        }
        ans %= mod;
        cout << p << ' ' << ans << endl;
    }

    return 0;
}