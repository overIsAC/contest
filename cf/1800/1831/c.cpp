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

int n;
vector<PII> edge[N];
int ans;

void dfs(int x, int fa, int w, int v) {
    ans = max(ans, w);
    for (auto &[y, id] : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x, w + (id < v), id);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back({v, i});
            edge[v].push_back({u, i});
        }
        ans = 0;
        dfs(1, 0, 0, 0);
        cout << ans + 1 << endl;
    }
    return 0;
}