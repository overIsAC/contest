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

int dp[N][22];
int n, k;
vector<int> edge[N];
int c[N];

void dfs1(int x, int fa) {
    dp[x][0] = c[x];
    for (int &y : edge[x]) {
        if (fa == y) {
            continue;
        }
        dfs1(y, x);
        for (int i = 1; i <= k; ++i) {
            dp[x][i] += dp[y][i - 1];
        }
    }
}

void dfs2(int x, int fa) {
    for (int &y : edge[x]) {
        if (fa == y) {
            continue;
        }
        for (int i = k; i >= 1; --i) {
            dp[y][i] += dp[x][i - 1];
            if (i >= 2) {
                dp[y][i] -= dp[y][i - 2];
            }
        }
        dfs2(y, x);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 0; j <= k; ++j) {
            ans += dp[i][j];
        }
        cout << ans << endl;
    }
    return 0;
}