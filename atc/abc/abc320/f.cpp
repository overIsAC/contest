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
const int N = 3 + 2e5;

int n, h;
int x[N], p[N], f[N];

int main() {
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> p[i] >> f[i];
    }
    vector<vector<LL>> dp(h + 1, vector<LL>(h + 1, 1e18));
    for (int i = 0; i <= h; ++i) {
        dp[h][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        vector<vector<LL>> ndp(h + 1, vector<LL>(h + 1, 1e18));
        for (int j = 0; j <= h; ++j) {
            for (int k = 0; k <= h; ++k) {
                if (j >= x[i] - x[i - 1] && k + x[i] - x[i - 1] <= h) {
                    int u = j - (x[i] - x[i - 1]);
                    int v = k + (x[i] - x[i - 1]);
                    ndp[u][v] = min(ndp[u][v], dp[j][k]);

                    if (i < n) {
                        u = min(j - (x[i] - x[i - 1]) + f[i], h);
                        v = k + (x[i] - x[i - 1]);
                        ndp[u][v] = min(ndp[u][v], dp[j][k] + p[i]);

                        u = j - (x[i] - x[i - 1]);
                        v = max(k + (x[i] - x[i - 1]) - f[i], 0);
                        ndp[u][v] = min(ndp[u][v], dp[j][k] + p[i]);
                    }
                }
            }
        }
        // cout << i << " --- " << endl;
        // for (auto &i : ndp) {
        //     for (auto &j : i) {
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }
        swap(dp, ndp);
    }
    LL ans = 1e18;
    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= i; ++j) {
            ans = min(ans, dp[i][j]);
        }
    }
    if (ans == 1e18) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}