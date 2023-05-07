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
const int N = 3 + 2333;

int n, m;
PII e[N];
vector<int> adj[N];
vector<int> edge[N];
int f[N], d[N];

int fa[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void dfs(int x, int fa) {
    f[x] = fa;
    d[x] = d[fa] + 1;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        adj[i].clear();
        edge[i].clear();
        f[i] = 0;
        d[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        adj[e[i].first].push_back(e[i].second);
        adj[e[i].second].push_back(e[i].first);
    }
    set<int> st;
    for (int i = 1; i <= m; ++i) {
        int u = e[i].first, v = e[i].second;
        if (find(u) == find(v)) {
            st.insert(i);
            continue;
        }
        fa[find(u)] = fa[find(v)];
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            dfs(i, 0);
        }
    }

    for (auto &id : st) {
        set<int> pt;
        vector<PII> ans;
        int u = e[id].first, v = e[id].second;
        ans.push_back({u, v});
        while (u != v) {
            pt.insert(u);
            pt.insert(v);
            if (d[u] > d[v]) {
                ans.push_back({u, f[u]});
                u = f[u];
            } else {
                ans.push_back({v, f[v]});
                pt.insert(v);
                v = f[v];
            }
        }
        pt.insert(u);
        // cout << "size " << ' ' << pt.size() << endl;
        int p = 0;
        for (auto &i : pt) {
            if (adj[i].size() >= 4) {
                p = i;
                break;
            }
        }
        if (!p) {
            continue;
        }
        // for (auto &i : pt) {
        //     cout << i << endl;
        // }
        int cnt = 0;
        for (auto &i : adj[p]) {
            if (pt.count(i)) {
                continue;
            }
            ++cnt;
            ans.push_back({p, i});
            if (cnt == 2) {
                break;
            }
        }
        if (cnt != 2) {
            continue;
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto &i : ans) {
            cout << i.first << ' ' << i.second << endl;
        }
        return;
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> e[i].first >> e[i].second;
        }
        solve();
    }
    return 0;
}