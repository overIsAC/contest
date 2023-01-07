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

vector<int> edge[N];
int n, m;
LL dp[N][4];

void dfs(int x, int fa) {
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        for (int i = 1; i <= 3; ++i) {
            LL temp = 0;
            for (int j = 1; j <= 3; ++j) {
                if (i == j) {
                    continue;
                }
                temp += dp[y][j];
            }
            dp[x][i] = dp[x][i] * temp % mod;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i][2] = dp[i][3] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int b, c;
        cin >> b >> c;
        dp[b][1] = dp[b][2] = dp[b][3] = 0;
        dp[b][c] = 1;
    }
    dfs(1, 0);
    cout << (dp[1][1] + dp[1][2] + dp[1][3]) % mod << endl;

    return 0;
}