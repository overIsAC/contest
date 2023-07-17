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

int n, a[N];
vector<int> edge[N];
int dp[N];

void dfs1(int x, int fa) {
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs1(y, x);
        dp[x] += max(0, dp[y] + (a[y] ? 1 : -1));
    }
}

void dfs2(int x, int fa) {
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dp[y] += max(0, dp[x] - max(0, dp[y] + (a[y] ? 1 : -1)) + (a[x] ? 1 : -1));
        dfs2(y, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] + (a[i] ? 1 : -1) << ' ';
    }
    return 0;
}