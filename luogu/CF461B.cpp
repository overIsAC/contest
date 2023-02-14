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
int n, a[N];
LL dp[N][2];

void dfs(int x, int fa) {
    dp[x][a[x]] = 1;
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        dp[x][1] = (dp[x][1] * dp[y][0] + dp[x][0] * dp[y][1] + dp[x][1] * dp[y][1]) % mod;
        dp[x][0] = (dp[x][0] * dp[y][0] + dp[x][0] * dp[y][1]) % mod;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v = i + 1;
        cin >> u;
        ++u;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << dp[1][1] << endl;

    return 0;
}