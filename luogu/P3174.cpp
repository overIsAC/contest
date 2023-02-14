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
const int N = 3 + 3e5;

vector<int> edge[N];
int ans = 1, dp[N];

void dfs(int x, int fa) {
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        ans = max(ans, dp[x] + dp[y] + 1 + (int)edge[x].size());
        dp[x] = max(dp[x], dp[y]);
    }
    dp[x] += edge[x].size();
    if (fa) {
        dp[x] -= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}