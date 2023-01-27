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

int n, m;
vector<int> edge[N];
int top[N], son[N], sz[N], dfn[N], id, fa[N];

struct Tree {
    struct TreeNode {
        int l, r;
        int value;
        void down(TreeNode &l, TreeNode &r) {
            if (value != -1) {
                l.value = value;
                r.value = value;
                value = -1;
            }
        }
    } node[N << 2];
    void update(int k, int l, int r, int v) {
        if (l <= node[k].l && node[k].r <= r) {
            node[k].value = v;
            return;
        }
        node[k].down(node[lson], node[rson]);
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid) {
            update(lson, l, r, v);
        }
        if (r > mid) {
            update(rson, l, r, v);
        }
    }
    int query(int k, int p) {
        if (node[k].l == node[k].r) {
            return node[k].value;
        }
        node[k].down(node[lson], node[rson]);
        int mid = node[k].l + node[k].r >> 1;
        if (p <= mid) {
            return query(lson, p);
        } else {
            return query(rson, p);
        }
    }
    void build(int k, int l, int r) {
        node[k] = {l, r, 0};
        if (l == r) {
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
    }
} tr;

void dfs1(int x, int fa) {
    sz[x] = 1;
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs1(y, x);
        sz[x] += sz[y];
        if (sz[son[x]] < sz[y]) {
            son[x] = y;
        }
    }
}

void dfs2(int x, int fa, int topf) {
    dfn[x] = ++id;
    top[x] = topf;
    ::fa[x] = fa;
    if (son[x]) {
        dfs2(son[x], x, topf);
    }
    for (int &y : edge[x]) {
        if (y == fa || y == son[x]) {
            continue;
        }
        dfs2(y, x, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    tr.build(1, 1, n);
    dfs1(1, 1);
    dfs2(1, 0, 1);

    cin >> m;

    while (m--) {
        int op, u;
        cin >> op >> u;
        if (op == 1) {
            tr.update(1, dfn[u], dfn[u] + sz[u] - 1, 1);
        } else if (op == 2) {
            while (u) {
                tr.update(1, dfn[top[u]], dfn[u], 0);
                u = fa[top[u]];
            }
        } else {
            cout << tr.query(1, dfn[u]) << '\n';
        }
    }

    return 0;
}