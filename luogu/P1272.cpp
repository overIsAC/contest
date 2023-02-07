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
const int N = 3 + 300;

int dp[N][N];
int temp[N];
int n, m;
vector<int> edge[N];
int ans;

void dfs(int x, int fa) {
    dp[x][1] = 0;
    for (int &y : edge[x]) {
        if (fa == y) {
            continue;
        }
        dfs(y, x);
        memset(temp, 0x3f, sizeof(temp));
        for (int i = 1; i <= n; ++i) {
            temp[i] = min(temp[i], dp[x][i] + 1);
            for (int j = 1; j <= n; ++j) {
                temp[i + j] = min(temp[i + j], dp[x][i] + dp[y][j]);
            }
        }
        memcpy(dp[x], temp, sizeof(temp));
    }
    if (x == 1) {
        ans = min(dp[x][m], ans);
    } else {
        ans = min(dp[x][m] + 1, ans);
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
    ans = 1e9;
    memset(dp, 0x3f, sizeof(dp));
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}