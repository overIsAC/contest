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
const int N = 3 + 1e5;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
} e[N];

int n, m;
int fa[N];
vector<PII> edge[N];
int d[N], f[N][20];
int mx[N][20];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void dfs(int x, int fa) {
    d[x] = d[fa] + 1;
    for (auto& [y, w] : edge[x]) {
        if (y == fa) {
            continue;
        }
        f[y][0] = x;
        mx[y][0] = w;
        for (int i = 1; i < 20; ++i) {
            f[y][i] = f[f[y][i - 1]][i - 1];
            mx[y][i] = max(mx[y][i - 1], mx[f[y][i - 1]][i - 1]);
        }
        dfs(y, x);
    }
}

PII lca(int x, int y) {
    int _mx = 0;
    if (d[x] > d[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; --i) {
        if (d[f[y][i]] >= d[x]) {
            _mx = max(_mx, mx[y][i]);
            y = f[y][i];
        }
    }
    if (x == y) {
        return {x, _mx};
    }
    for (int i = 19; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            _mx = max(_mx, mx[x][i]);
            _mx = max(_mx, mx[y][i]);
            x = f[x][i];
            y = f[y][i];
        }
    }
    return {f[x][0], _mx};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        auto [u, v, w] = e[i];
        if (find(u) == find(v)) {
            continue;
        }
        fa[find(u)] = find(v);
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    dfs(1, 0);
    int q;
    cin >> q;
    int ans = 0;
    while (q--) {
        int m;
        cin >> m;
        vector<int> b(m);
        for (auto& i : b) {
            cin >> i;
        }
        int g = b[0];
        for (auto& i : b) {
            auto [gg, mx] = lca(g, i);
            ans = max(ans, mx);
            g = gg;
        }
    }
    cout << ans << endl;

    return 0;
}