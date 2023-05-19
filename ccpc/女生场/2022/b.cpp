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

int n, m, q;
vector<int> edge[N];
int a[N];
int p[N], r[N], id;
int f[N][20], d[N];
LL dis[N];

int lca(int x, int y) {
    if (d[x] > d[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; --i) {
        if (d[x] <= d[f[y][i]]) {
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

void dfs(int x, int fa) {
    p[x] = ++id;
    r[id] = x;
    d[x] = d[fa] + 1;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dis[y] = dis[x] + a[y];
        f[y][0] = x;
        for (int i = 1; i < 20; ++i) {
            f[y][i] = f[f[y][i - 1]][i - 1];
        }
        dfs(y, x);
    }
}

LL getDist(int x, int y) {
    return dis[x] + dis[y] - 2 * dis[lca(x, y)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            edge[i].clear();
        }
        id = 0;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1, 0);

        set<int> st;
        LL cnt = 0;

        auto add = [&](int w) {
            if (st.size()) {
                auto it = st.lower_bound(p[w]);
                if (it == st.end()) {
                    it = st.begin();
                }
                int u = *it;
                it = st.lower_bound(p[w]);
                if (it == st.begin()) {
                    it = --st.end();
                } else {
                    --it;
                }
                int v = *it;
                cnt -= getDist(r[u], r[v]);
                cnt += getDist(r[u], w);
                cnt += getDist(r[v], w);
            }
            st.insert(p[w]);
        };

        auto del = [&](int w) {
            st.erase(p[w]);
            if (st.size()) {
                auto it = st.lower_bound(p[w]);
                if (it == st.end()) {
                    it = st.begin();
                }
                int u = *it;
                it = st.lower_bound(p[w]);
                if (it == st.begin()) {
                    it = --st.end();
                } else {
                    --it;
                }
                int v = *it;
                cnt += getDist(r[u], r[v]);
                cnt -= getDist(r[u], w);
                cnt -= getDist(r[v], w);
            }
        };

        while (m--) {
            int a;
            cin >> a;
            add(a);
        }
        while (q--) {
            int op, u;
            cin >> op >> u;
            if (op == 1) {
                add(u);
            } else {
                del(u);
            }
            LL ans = cnt / 2;
            if (st.size()) {
                ans += a[lca(r[*st.begin()], r[*st.rbegin()])];
            }
            cout << ans << endl;
        }
    }
    return 0;
}