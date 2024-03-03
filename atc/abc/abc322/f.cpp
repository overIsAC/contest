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

int n, q;
char s[N];

struct TreeNode {
    int l, r;
    int max[2], lmax[2], rmax[2];
    int sum;
    int lazy;
    void reverse() {
        swap(max[0], max[1]);
        swap(lmax[0], lmax[1]);
        swap(rmax[0], rmax[1]);
        sum = r - l + 1 - sum;
        lazy ^= 1;
    }
} tr[N << 2];

void up(TreeNode &rt, const TreeNode &l, const TreeNode &r) {
    rt.l = l.l;
    rt.r = r.r;

    rt.max[0] = max(l.max[0], r.max[0]);
    rt.max[0] = max(rt.max[0], l.rmax[0] + r.lmax[0]);
    rt.lmax[0] = l.lmax[0];
    if (l.sum == 0) {
        rt.lmax[0] += r.lmax[0];
    }
    rt.rmax[0] = r.rmax[0];
    if (r.sum == 0) {
        rt.rmax[0] += l.rmax[0];
    }

    rt.max[1] = max(l.max[1], r.max[1]);
    rt.max[1] = max(rt.max[1], l.rmax[1] + r.lmax[1]);
    rt.lmax[1] = l.lmax[1];
    if (l.sum == l.r - l.l + 1) {
        rt.lmax[1] += r.lmax[1];
    }
    rt.rmax[1] = r.rmax[1];
    if (r.sum == r.r - r.l + 1) {
        rt.rmax[1] += l.rmax[1];
    }

    rt.sum = l.sum + r.sum;
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        tr[k].max[s[r] - '0'] = 1;
        tr[k].lmax[s[r] - '0'] = 1;
        tr[k].rmax[s[r] - '0'] = 1;
        tr[k].sum = s[r] - '0';
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(tr[k], tr[lson], tr[rson]);
}

void down(int k) {
    if (tr[k].lazy) {
        tr[lson].reverse();
        tr[rson].reverse();
        tr[k].lazy = 0;
    }
}

void update(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].reverse();
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update(lson, l, r);
    }
    if (r > mid) {
        update(rson, l, r);
    }
    up(tr[k], tr[lson], tr[rson]);
}

TreeNode query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k];
    }
    down(k);
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
    cin >> n >> q;
    cin >> s + 1;
    build(1, 1, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            update(1, l, r);
        } else {
            auto t = query(1, l, r);
            cout << t.max[1] << endl;
        }
    }
    return 0;
}