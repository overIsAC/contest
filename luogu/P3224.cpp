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

int ls[N * 50], rs[N * 50], sum[N * 50], num[N * 50];
int id, root[N];
int n, m, a[N];

int fa[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void update(int& rt, int l, int r, int p, int v) {
    if (!rt) {
        rt = ++id;
    }
    sum[rt] = 1;
    if (l == r) {
        num[rt] = v;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
        update(ls[rt], l, mid, p, v);
    } else {
        update(rs[rt], mid + 1, r, p, v);
    }
}

int merge(int u, int v) {
    if (!u || !v) {
        return u | v;
    }
    ls[u] = merge(ls[u], ls[v]);
    rs[u] = merge(rs[u], rs[v]);
    sum[u] = sum[ls[u]] + sum[rs[u]];
    return u;
}

int query(int rt, int l, int r, int k) {
    if (l == r) {
        return num[rt];
    }
    int mid = l + r >> 1;
    if (sum[ls[rt]] >= k) {
        return query(ls[rt], l, mid, k);
    } else {
        return query(rs[rt], mid + 1, r, k - sum[ls[rt]]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        update(root[i], 1, n, a[i], i);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        u = find(u);
        v = find(v);
        if (u == v) {
            continue;
        }
        fa[v] = fa[u];
        root[u] = merge(root[u], root[v]);
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        char op;
        cin >> op >> u >> v;
        if (op == 'Q') {
            u = find(u);
            if (sum[root[u]] < v) {
                cout << -1 << endl;
            } else {
                cout << query(root[u], 1, n, v) << endl;
            }
        } else {
            u = find(u);
            v = find(v);
            if (u == v) {
                continue;
            }
            fa[v] = fa[u];
            root[u] = merge(root[u], root[v]);
        }
    }

    return 0;
}