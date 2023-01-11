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
const int N = 3 + 1e5;

vector<int> edge[N];
int n, k;
int dp[N][102][2][2];
int temp[102][2][2];
int sz[N];

void dfs(int x, int fa) {
    dp[x][0][0][0] = 1;
    dp[x][1][1][0] = 1;
    sz[x] = 1;
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        for (int i = 0; i <= sz[x]; ++i) {
            memcpy(temp[i], dp[x][i], sizeof(temp[i]));
            memset(dp[x][i], 0, sizeof(temp[i]));
        }

        for (int i = 0; i <= sz[x]; ++i) {
            for (int j = 0; j <= sz[y] && i + j <= k; ++j) {
                dp[x][i + j][1][0] = (dp[x][i + j][1][0] + (LL)temp[i][1][0] * dp[y][j][0][0]) % mod;
                dp[x][i + j][1][1] = (dp[x][i + j][1][1] + (LL)temp[i][1][1] * dp[y][j][0][0]) % mod;

                dp[x][i + j][0][0] = (dp[x][i + j][0][0] + (LL)temp[i][0][0] * dp[y][j][0][1]) % mod;
                dp[x][i + j][0][1] = (dp[x][i + j][0][1] + (LL)temp[i][0][1] * dp[y][j][0][1]) % mod;
                dp[x][i + j][1][0] = (dp[x][i + j][1][0] + (LL)temp[i][1][0] * dp[y][j][0][1]) % mod;
                dp[x][i + j][1][1] = (dp[x][i + j][1][1] + (LL)temp[i][1][1] * dp[y][j][0][1]) % mod;

                dp[x][i + j][1][1] = (dp[x][i + j][1][1] + (LL)temp[i][1][0] * dp[y][j][1][0] + (LL)temp[i][1][1] * dp[y][j][1][0]) % mod;

                dp[x][i + j][0][1] = (dp[x][i + j][0][1] + (LL)temp[i][0][0] * dp[y][j][1][1] + (LL)temp[i][0][1] * dp[y][j][1][1]) % mod;
                dp[x][i + j][1][1] = (dp[x][i + j][1][1] + (LL)temp[i][1][0] * dp[y][j][1][1] + (LL)temp[i][1][1] * dp[y][j][1][1]) % mod;
            }
        }
        sz[x] += sz[y];
        sz[x] = min(sz[x], k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1][k][0][1] + dp[1][k][1][1]) % mod << endl;
    return 0;
}