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
const int N = 3 + 200;

int n, k, a[N];
vector<int> edge[N];
int dp[N][N], t[N];

void dfs(int x, int fa) {
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        memset(t, 0, sizeof(t));
        for (int q = 0; q <= n; ++q) {
            for (int w = 0; w <= n; ++w) {
                if (q + w + 1 > k) {
                    t[min(q, w + 1)] = max(t[min(q, w + 1)], dp[x][q] + dp[y][w]);
                }
            }
        }
        memcpy(dp[x], t, sizeof(t));
    }
    for (int i = k + 1; i <= n; ++i) {
        dp[x][0] = max(dp[x][0], dp[x][i] + a[x]);
    }
    dp[x][0] = max(dp[x][0], a[x]);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[1][i]);
    }
    cout << ans << endl;

    return 0;
}