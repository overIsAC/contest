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

int n, m, a[N];

struct TreeNode {
    int l, r;
    int max;
    LL sum;
};

TreeNode operator+(const TreeNode &l, const TreeNode &r) {
    TreeNode ans = {};
    ans.l = l.l;
    ans.r = r.r;
    ans.max = max(l.max, r.max);
    ans.sum = l.sum + r.sum;
    return ans;
}

struct Tree {
    TreeNode node[N << 2];
    void up(int k) {
        node[k] = node[lson] + node[rson];
    }
    void build(int k, int l, int r) {
        if (l == r) {
            node[k] = {l, r, a[r], a[r]};
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        node[k] = node[lson] + node[rson];
    }

    TreeNode query(int k, int l, int r) {
        if (l <= node[k].l && node[k].r <= r) {
            return node[k];
        }
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid && mid < r) {
            return query(lson, l, r) + query(rson, l, r);
        }
        if (l <= mid) {
            return query(lson, l, r);
        }
        return query(rson, l, r);
    }
    void update(int k, int p, int v) {
        if (node[k].l == node[k].r) {
            node[k].max = node[k].sum = v;
            return;
        }
        int mid = node[k].l + node[k].r >> 1;
        if (p <= mid) {
            update(lson, p, v);
        } else {
            update(rson, p, v);
        }
        up(k);
    }
    void update(int k, int l, int r, int v) {
        if (v > node[k].max) {
            return;
        }
        if (node[k].l == node[k].r) {
            node[k].max = node[k].sum = node[k].sum % v;
            return;
        }
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

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    tr.build(1, 1, n);
    while (m--) {
        int type, l, r, x, k;
        cin >> type;
        if (type == 1) {
            cin >> l >> r;
            cout << tr.query(1, l, r).sum << endl;
        } else if (type == 2) {
            cin >> l >> r >> x;
            tr.update(1, l, r, x);
        } else {
            cin >> k >> x;
            tr.update(1, k, x);
        }
    }
    return 0;
}