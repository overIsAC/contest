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
const int N = 3 + 1e6;

int sz[N];
vector<int> edge[N];
LL temp, dp[N];
int p;
int n;

void dfs(int x, int fa) {
    sz[x] = 1;
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        sz[x] += sz[y];
    }
}

void dfs2(int x, int fa) {
    if (temp < dp[x]) {
        p = x;
        temp = dp[x];
    }
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dp[y] = dp[x] + n - sz[y] * 2;
        dfs2(y, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    p = 1;

    dfs(1, 0);
    dfs2(1, 0);

    cout << p << endl;

    return 0;
}