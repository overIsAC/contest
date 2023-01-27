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
int a[N];

struct Tree {
    struct TreeNode {
        int l, r;
        int lazy, value;
        void up(TreeNode &l, TreeNode &r) {
            value = l.value + r.value;
        }
        void down(TreeNode &l, TreeNode &r) {
            if (lazy % 2) {
                l.lazy += 1;
                r.lazy += 1;
                l.value = l.r - l.l + 1 - l.value;
                r.value = r.r - r.l + 1 - r.value;
                lazy = 0;
            }
        }
    } node[N << 2];
    void update(int k, int l, int r) {
        if (l <= node[k].l && node[k].r <= r) {
            node[k].value = node[k].r - node[k].l + 1 - node[k].value;
            node[k].lazy += 1;
            return;
        }
        node[k].down(node[lson], node[rson]);
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid) {
            update(lson, l, r);
        }
        if (r > mid) {
            update(rson, l, r);
        }
        node[k].up(node[lson], node[rson]);
    }
    int query(int k, int l, int r) {
        if (l <= node[k].l && node[k].r <= r) {
            return node[k].value;
        }
        node[k].down(node[lson], node[rson]);
        int mid = node[k].l + node[k].r >> 1, ans = 0;
        if (l <= mid) {
            ans += query(lson, l, r);
        }
        if (r > mid) {
            ans += query(rson, l, r);
        }
        return ans;
    }
} tr[26];

void build(int k, int l, int r) {
    for (int i = 0; i < 20; ++i) {
        tr[i].node[k] = {l, r, 0, 0};
    }
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

int main() {
    cin >> n;
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (a[i] >> j & 1) {
                tr[j].update(1, i, i);
            }
        }
    }

    cin >> m;

    while (m--) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op == 1) {
            LL ans = 0;
            for (int i = 0; i < 20; ++i) {
                ans += (LL)tr[i].query(1, l, r) << i;
            }
            cout << ans << endl;
        } else {
            cin >> x;
            for (int i = 0; i < 20; ++i) {
                if (x >> i & 1) {
                    tr[i].update(1, l, r);
                }
            }
        }
    }

    return 0;
}