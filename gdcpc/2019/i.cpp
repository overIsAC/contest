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
const int N = 3 + 5e3;

int n, m, k;
LL dp[N][N];
LL temp[N];
vector<int> edge[N];
bool vis[N];
int d[N];


int main() {
    while (~scanf("%d%d%d", &n, &m, &k)) {
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
            edge[i].clear();
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1, 0);
    }
    return 0;
}