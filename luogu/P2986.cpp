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

int a[N];
vector<PII> edge[N];
LL dp[N];
int sz[N];
int n;

void dfs1(int x, int fa) {
    sz[x] = a[x];
    for (auto &e : edge[x]) {
        int &y = e.first, &w = e.second;
        if (y == fa) {
            continue;
        }
        dfs1(y, x);
        sz[x] += sz[y];
        dp[x] += (LL)w * sz[y] + dp[y];
    }
}

void dfs2(int x, int fa) {
    for (auto &e : edge[x]) {
        int &y = e.first, &w = e.second;
        if (y == fa) {
            continue;
        }
        dp[y] += dp[x] - dp[y] - (LL)w * sz[y] + (LL)w * (sz[1] - sz[y]);
        dfs2(y, x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dfs1(1, 0);
    dfs2(1, 0);
    LL ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}