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

struct TreeNode {
    int l, r;
    int p[10];
    int value;
    void reset() {
        for (int i = 0; i <= 9; ++i) {
            p[i] = INT_MAX;
        }
        value = INT_MAX;
    }
} tr[N << 2];

int n, a[N], m;

void up(TreeNode &rt, const TreeNode &l, const TreeNode &r) {
    rt.value = min(l.value, r.value);
    for (int i = 0; i <= 9; ++i) {
        if (l.p[i] < INT_MAX && r.p[i] < INT_MAX) {
            rt.value = min(rt.value, l.p[i] + r.p[i]);
        }
        rt.p[i] = min(l.p[i], r.p[i]);
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        tr[k].reset();
        int v = a[r];
        for (int i = 0; i <= 9; ++i) {
            if (v % 10) {
                tr[k].p[i] = a[r];
            }
            v /= 10;
        }
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(tr[k], tr[lson], tr[rson]);
}

void update(int k, int p, int v) {
    if (tr[k].l == tr[k].r) {
        tr[k].reset();
        int r = tr[k].r;
        a[r] = v;
        for (int i = 0; i <= 9; ++i) {
            if (v % 10) {
                tr[k].p[i] = a[r];
            }
            v /= 10;
        }
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) {
        update(lson, p, v);
    } else {
        update(rson, p, v);
    }
    up(tr[k], tr[lson], tr[rson]);
}

TreeNode query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k];
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid && mid < r) {
        TreeNode ans;
        up(ans, query(lson, l, r), query(rson, l, r));
        return ans;
    }
    if (l <= mid) {
        return query(lson, l, r);
    } else {
        return query(rson, l, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int i, x, l, r, op;
        cin >> op;
        if (op == 1) {
            cin >> i >> x;
            update(1, i, x);
        } else {
            cin >> l >> r;
            auto node = query(1, l, r);
            int ans = node.value;

            if (ans == INT_MAX) {
                ans = -1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}