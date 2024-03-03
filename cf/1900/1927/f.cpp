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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> fa(n + 1);
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    function<int(int)> find = [&](int p) {
        return fa[p] == p ? p : fa[p] = find(fa[p]);
    };
    vector<vector<PII>> edge(n + 1);
    vector<vector<int>> e;
    vector<int> d(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(20));
    vector<vector<int>> mn(n + 1, vector<int>(20, 1e9));

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({w, u, v});
    }
    sort(e.begin(), e.end());
    for (auto& i : e) {
        int u = find(i[1]), v = find(i[2]);
        if (u == v) {
            i.push_back(0);
            continue;
        }
        i.push_back(1);
        fa[u] = v;
        edge[i[1]].push_back({i[2], i[0]});
        edge[i[2]].push_back({i[1], i[0]});
    }

    function<void(int, int)> dfs = [&](int x, int fa) {
        d[x] = d[fa] + 1;
        f[x][0] = fa;
        for (int i = 1; i < 20; ++i) {
            f[x][i] = f[f[x][i - 1]][i - 1];
            mn[x][i] = min(mn[x][i - 1], mn[f[x][i - 1]][i - 1]);
        }
        for (auto& [y, w] : edge[x]) {
            if (y == fa) {
                continue;
            }
            mn[y][0] = w;
            dfs(y, x);
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            dfs(i, 0);
        }
    }

    auto lca = [&](int u, int v) -> PII {
        int _mn = 1e9;
        if (d[u] > d[v]) {
            swap(u, v);
        }
        for (int i = 19; i >= 0; --i) {
            if (d[u] <= d[f[v][i]]) {
                _mn = min(_mn, mn[v][i]);
                v = f[v][i];
            }
        }
        if (u == v) {
            return {u, _mn};
        }
        for (int i = 19; i >= 0; --i) {
            if (f[u][i] != f[v][i]) {
                _mn = min(_mn, mn[u][i]);
                _mn = min(_mn, mn[v][i]);
                u = f[u][i];
                v = f[v][i];
            }
        }
        _mn = min(_mn, mn[u][0]);
        _mn = min(_mn, mn[v][0]);
        return {f[u][0], _mn};
    };

    int idx = 0;
    int now = 1e9;

    for (int j = 0; j < e.size(); ++j) {
        auto& i = e[j];
        if (i.back()) {
            continue;
        }
        auto [g, mn] = lca(i[1], i[2]);

        if (mn < now) {
            idx = j;
            now = mn;
        }
    }

    vector<int> u, v;

    int x = e[idx][1], y = e[idx][2];
    while (x != y) {
        if (d[x] > d[y]) {
            u.push_back(x);
            x = f[x][0];
        } else {
            v.push_back(y);
            y = f[y][0];
        }
    }
    cout << now << ' ' << u.size() + v.size() + 1 << endl;
    u.push_back(x);
    u.insert(u.end(), v.rbegin(), v.rend());
    for (auto& i : u) {
        cout << i << ' ';
    }
    // cout << endl;
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}