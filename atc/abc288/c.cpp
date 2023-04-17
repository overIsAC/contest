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
const int N = 3 + 2e5;

int n, m;
vector<int> edge[N];
int ans, vis[N];
int sz;

void dfs(int x) {
    if (vis[x]) {
        return;
    }
    ++sz;
    vis[x] = 1;
    for (auto &y : edge[x]) {
        dfs(y);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    ans = m;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        sz = 0;
        dfs(i);
        ans -= sz - 1;
    }
    cout << ans << endl;
    return 0;
}