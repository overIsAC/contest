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

int n;
vector<int> edge[N];
int dp[N][2];

void dfs(int x, int fa) {
    ++dp[x][1];
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        dp[x][0] += dp[y][1];
        dp[x][1] += min(dp[y][0], dp[y][1]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        int m;
        cin >> u >> m;
        ++u;
        while (m--) {
            cin >> v;
            ++v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }
    dfs(1, 0);
    cout << min(dp[1][0], dp[1][1]) << endl;
    return 0;
}