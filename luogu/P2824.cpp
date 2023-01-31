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
int a[N], q;

struct TreeNode {
    int l, r;
    int v, lazy;
};

struct Operator {
    int op, l, r;
} b[N];

TreeNode operator+(const TreeNode &l, const TreeNode &r) {
    TreeNode ans = {};
    ans.l = l.l;
    ans.r = r.r;
    ans.v = l.v + r.v;
    ans.lazy = -1;
    return ans;
}

struct Tree {
    TreeNode node[N << 2];
    void down(int k) {
        if (node[k].lazy != -1) {
            node[lson].v = node[k].lazy * (node[lson].r - node[lson].l + 1);
            node[rson].v = node[k].lazy * (node[rson].r - node[rson].l + 1);
            node[lson].lazy = node[k].lazy;
            node[rson].lazy = node[k].lazy;
            node[k].lazy = -1;
        }
    }
    void up(int k) {
        node[k] = node[lson] + node[rson];
    }
    void build(int k, int l, int r, int v) {
        if (l == r) {
            node[k] = {l, r, a[r] > v, -1}; 
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid, v);
        build(rson, mid + 1, r, v);
        node[k] = node[lson] + node[rson];
    }

    TreeNode query(int k, int l, int r) {
        if (l <= node[k].l && node[k].r <= r) {
            return node[k];
        }
        down(k);
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid && mid < r) {
            return query(lson, l, r) + query(rson, l, r);
        }
        if (l <= mid) {
            return query(lson, l, r);
        }
        return query(rson, l, r);
    }
    void update(int k, int l, int r, int v) {
        if (l <= node[k].l && node[k].r <= r) {
            node[k].v = (node[k].r - node[k].l + 1) * v;
            node[k].lazy = v;
            return;
        }
        down(k);
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid) {
            update(lson, l, r, v);
        }
        if (r > mid) {
            update(rson, l, r, v);
        }
        up(k);
    }
} tr;

bool ok(int v) {
    tr.build(1, 1, n, v);
    for (int i = 1; i <= m; ++i) {
        int y = tr.query(1, b[i].l, b[i].r).v;
        int x = b[i].r - b[i].l + 1 - y;
        if (b[i].op) {
            if (x) {
                tr.update(1, b[i].l, b[i].l + x - 1, 0);
            }
            if (y) {
                tr.update(1, b[i].r - y + 1, b[i].r, 1);
            }
        } else {
            if (y) {
                tr.update(1, b[i].l, b[i].l + y - 1, 1);
            }
            if (x) {
                tr.update(1, b[i].r - x + 1, b[i].r, 0);
            }
        }
    }
    return tr.query(1, q, q).v == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].op >> b[i].l >> b[i].r;
    }
    cin >> q;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}