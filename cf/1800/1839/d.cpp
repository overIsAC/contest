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
const int N = 3 + 555;

int n, a[N];
int dp[N][N];
int ans[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][1] = i - 1;
            }
            for (int j = 0; j < i; ++j) {
                if (a[j] > a[i]) {
                    continue;
                }
                if (i == j + 1) {
                    for (int k = 0; k <= n; ++k) {
                        dp[i][k] = min(dp[i][k], dp[j][k]);
                    }
                }
                for (int k = 1; k <= i; ++k) {
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + i - j - 1);
                }
            }
        }
        memset(ans, 0x3f, sizeof(ans));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                int w = j;
                if (i < n) {
                    ++w;
                }
                ans[w] = min(ans[w], dp[i][j] + n - i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            ans[i] = min(ans[i], ans[i - 1]);
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
/*
5
2 3 4 5 1
*/