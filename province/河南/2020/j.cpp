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
// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 3e5;

int n, a[N], q;

struct TreeNode {
    int l, r;
    int sum, v;
} tr[N << 2];

void up(int k) {
    tr[k].sum = (tr[lson].sum + tr[rson].sum) % mod;
    tr[k].v = tr[lson].v | tr[rson].v;
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {  
        tr[k].sum = (LL)a[r] * a[r] % mod;
        tr[k].v = a[r];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(k);
}

void update(int k, int l, int r, int x) {
    if ((tr[k].v & x) == tr[k].v) {
        return;
    }
    if (tr[k].l == tr[k].r) {
        tr[k].v &= x;
        tr[k].sum = (LL)tr[k].v * tr[k].v % mod;
        return;
    }
    int mid = (tr[k].l + tr[k].r) / 2;
    if (l <= mid) {
        update(lson, l, r, x);
    }
    if (r > mid) {
        update(rson, l, r, x);
    }
    up(k);
}

int query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k].sum;
    }
    int mid = (tr[k].l + tr[k].r) / 2;
    int ans = 0;
    if (l <= mid) {
        ans += query(lson, l, r);
    }
    if (r > mid) {
        ans += query(rson, l, r);
    }
    return ans % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            update(1, l, r, x);
        } else {
            cout << query(1, l, r) << '\n';
        }
    }
    return 0;
}