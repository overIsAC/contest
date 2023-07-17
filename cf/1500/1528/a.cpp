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
int l[N], r[N];
LL dp[N][2];

void dfs(int x, int fa) {
    dp[x][0] = dp[x][1] = 0;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        dp[x][0] += max(dp[y][0] + abs(l[x] - l[y]), dp[y][1] + abs(l[x] - r[y]));
        dp[x][1] += max(dp[y][0] + abs(r[x] - l[y]), dp[y][1] + abs(r[x] - r[y]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            cin >> l[i] >> r[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1, 0);
        cout << max(dp[1][0], dp[1][1]) << '\n';
    }
    return 0;
}