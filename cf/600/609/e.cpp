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

int n, m;
vector<PII> edge[N];
int f[N][20], mx[N][20];
int vis[N];
LL ans[N];
int d[N];

struct Edge {
    int u, v, w, id;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
} e[N];

int fa[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void dfs(int x, int fa) {
    d[x] = d[fa] + 1;
    for (auto& e : edge[x]) {
        int y = e.first, w = e.second;
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

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].id = i;
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    LL sum = 0;
    for (int i = 1; i <= m; ++i) {
        int u = find(e[i].u), v = find(e[i].v);
        if (u == v) {
            continue;
        }
        sum += e[i].w;
        vis[i] = 1;
        fa[u] = v;
        edge[e[i].u].push_back({e[i].v, e[i].w});
        edge[e[i].v].push_back({e[i].u, e[i].w});
    }
    dfs(1, 0);

    auto get = [&](int x, int y) {
        if (d[x] > d[y]) {
            swap(x, y);
        }
        int ans = 0;
        for (int i = 19; i >= 0; --i) {
            if (d[x] <= d[f[y][i]]) { 
                ans = max(ans, mx[y][i]);
                y = f[y][i];
            }
        }
        if (x == y) {
            return ans;
        }
        for (int i = 19; i >= 0; --i) {
            if (f[x][i] != f[y][i]) {
                ans = max(ans, mx[x][i]);
                ans = max(ans, mx[y][i]);
                x = f[x][i];
                y = f[y][i];
            }
        }
        ans = max(mx[x][0], ans);
        ans = max(mx[y][0], ans);
        return ans;
    };

    for (int i = 1; i <= m; ++i) {
        if (vis[i]) {
            ans[e[i].id] = sum;
            continue;
        }
        ans[e[i].id] = sum - get(e[i].u, e[i].v) + e[i].w;
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}