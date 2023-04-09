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

int n, m;
map<int, int> id;
vector<PII> edge[N];
int fa[N];
LL d[44][N];
int r[44];
int f[N][20];
LL dis[N];
int dep[N];

void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    for (auto &e : edge[x]) {
        int y = e.first;
        if (y == fa) {
            continue;
        }
        dis[y] = dis[x] + e.second;
        f[y][0] = x;
        for (int i = 1; i < 20; ++i) {
            f[y][i] = f[f[y][i - 1]][i - 1];
        }
        dfs(y, x);
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; --i) {
        if (dep[x] <= dep[f[y][i]]) {
            y = f[y][i];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = 19; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int getId(int x) {
    if (!id[x]) {
        id[x] = id.size();
        r[id.size()] = x;
    }
    return id[x];
}

LL getDis(int x, int y) {
    int g = lca(x, y);
    return dis[x] + dis[y] - 2 * dis[g];
}

bool vis[N];

void bfs(int st, LL d[N]) {
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<LL, int>> q;
    q.push({0, st});
    d[st] = 0;
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;
        for (auto &e : edge[x]) {
            int y = e.first, w = e.second;
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                q.push({-d[y], y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    vector<vector<int>> extra;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        if (find(u) == find(v)) {
            extra.push_back({u, v, w});
            u = getId(u);
            v = getId(v);
            continue;
        }
        fa[find(u)] = find(v);
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dfs(1, 0);

    for (auto &i : extra) {
        edge[i[0]].push_back({i[1], i[2]});
        edge[i[1]].push_back({i[0], i[2]});
    }

    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= id.size(); ++i) {
        bfs(r[i], d[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        LL ans = getDis(x, y);
        for (int i = 1; i <= id.size(); ++i) {
            ans = min(ans, d[i][x] + d[i][y]);
        }
        cout << ans << endl;
    }
    return 0;
}