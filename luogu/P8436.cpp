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
const int N = 3 + 5e5;
const int M = 3 + 2e6;

int n, m;
vector<PII> edge[N];
int dfn[N], low[N], timer;
int cut[M];
int vis[N];

int id;
vector<int> ve[N];

void tarjan(int x, int inId) {
    dfn[x] = ++timer;
    low[x] = timer;
    for (auto [y, id] : edge[x]) {
        if (!dfn[y]) {
            tarjan(y, id);
            low[x] = min(low[x], low[y]);
            if (dfn[x] < low[y]) {
                cut[id] = 1;
            }
        } else if (id != inId) {
            low[x] = min(low[x], low[y]);
        }
    }
}

void dfs(int x) {
    vis[x] = 1;
    ve[id].push_back(x);
    for (auto [y, id] : edge[x]) {
        if (vis[y] || cut[id]) {
            continue;
        }
        dfs(y);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++id;
            dfs(i);
        }
    }
    cout << id << endl;
    for (int i = 1; i <= id; ++i) {
        cout << ve[i].size();
        for (auto& j : ve[i]) {
            cout << ' ' << j;
        }
        cout << endl;
    }
    return 0;
}