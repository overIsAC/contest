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

int n, k;
vector<int> edge[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        if (k == 2) {
            cout << n * (n - 1) / 2 << endl;
            continue;
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            vector dp(n + 1, vector<int>(n + 1));
            vector cnt(n + 1, 0);
            function<void(int, int, int)> dfs = [&](int x, int fa, int d) {
                ++cnt[d];
                for (auto &y : edge[x]) {
                    if (y == fa) {
                        continue;
                    }
                    dfs(y, x, d + 1);
                }
            };
            for (int &j : edge[i]) {
                for (int i = 0; i <= n; ++i) {
                    cnt[i] = 0;
                }
                dfs(j, i, 1);
                for (int q = 1; q <= n; ++q) {
                    for (int w = k - 1; w >= 1; --w) {
                        dp[q][w + 1] = (dp[q][w + 1] + (LL)dp[q][w] * cnt[q]) % mod;
                    }
                    dp[q][1] += cnt[q];
                }
            }
            for (int j = 1; j <= n; ++j) {
                ans += dp[j][k];
            }
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}