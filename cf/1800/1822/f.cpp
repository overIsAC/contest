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

vector<int> edge[N];
int n, k, c, d1[N], d2[N], d3[N];

void dfs(int x, int fa, int *d) {
    d[x] = d[fa] + 1;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x, d);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k >> c;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1, 0, d1);
        int p = 1;
        for (int i = 1; i <= n; ++i) {
            if (d1[p] < d1[i]) {
                p = i;
            }
        }
        dfs(p, 0, d2);
        p = 1;
        for (int i = 1; i <= n; ++i) {
            if (d2[p] < d2[i]) {
                p = i;
            }
        }
        dfs(p, 0, d3);
        LL ans = (LL)(d1[p] - 1) * k;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, -(LL)(d1[i] - 1) * c + (LL)(d2[i] - 1) * k);
            ans = max(ans, -(LL)(d1[i] - 1) * c + (LL)(d3[i] - 1) * k);
        }
        cout << ans << endl;
    }
    return 0;
}