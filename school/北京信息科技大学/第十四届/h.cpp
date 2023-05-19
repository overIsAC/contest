#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 2e5;

int n, m, a[N];
vector<int> edge[N];
int dfn[N], son[N], sz[N], fa[N], id, d[N], top[N];

LL tr[2][N];

void add(LL *tr, int p, LL v) {
    for (; p <= n; p += p & -p) {
        tr[p] += v;
    }
}

LL ask(LL *tr, int p) {
    LL ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

void dfs1(int x, int fa) {
    ::fa[x] = fa;
    sz[x] = 1;
    d[x] = d[fa] + 1;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs1(y, x);
        if (sz[son[x]] < sz[y]) {
            son[x] = y;
        }
        sz[x] += sz[y];
    }
}

void dfs2(int x, int fa, int topf) {
    top[x] = topf;
    dfn[x] = ++id;
    if (son[x]) {
        dfs2(son[x], x, topf);
    }
    for (auto &y : edge[x]) {
        if (y == fa || y == son[x]) {
            continue;
        }
        dfs2(y, x, y);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);

    /*
    5 5
    1 2 1 1 2
    1 2
    1 3
    2 4
    2 5
    1 2 3

    */

    auto query = [&](int x) {
        LL ans = a[x];
        int z = x;
        while (x) {
            int y = top[x];
            int v = d[z] - d[y] & 1;
            if (z == 0) {
                ans -= ask(tr[v], dfn[x]) - ask(tr[v], dfn[y] - 1);
                ans += ask(tr[!v], dfn[x]) - ask(tr[!v], dfn[y] - 1);
            } else {
                ans += ask(tr[v], dfn[x]) - ask(tr[v], dfn[y] - 1);
                ans -= ask(tr[!v], dfn[x]) - ask(tr[!v], dfn[y] - 1);
            }
            x = fa[y];
        }
        return ans;
    };

    while (m--) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            cin >> y;
            add(tr[d[x] - d[top[x]] & 1], dfn[x], y);
            // for (int i = 1; i <= n; ++i) {
            //     cout << i << ' ' << query(i) << endl;
            // }
        } else {
            cout << query(x) << endl;
        }
    }

    return 0;
}