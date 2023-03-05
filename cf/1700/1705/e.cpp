#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

struct {
    int l, r;
    int sum;
    int tag;
} tr[N << 2];

int n, m, a[N];
int b[N];
const int t = 1e6;
int k, l;

void up(int k) { tr[k].sum = tr[lson].sum + tr[rson].sum; }

void down(int k) {
    if (tr[k].tag != -1) {
        tr[lson].sum = (tr[lson].r - tr[lson].l + 1) * tr[k].tag;
        tr[rson].sum = (tr[rson].r - tr[rson].l + 1) * tr[k].tag;
        tr[lson].tag = tr[k].tag;
        tr[rson].tag = tr[k].tag;
        tr[k].tag = -1;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    tr[k].tag = -1;
    if (l == r) {
        tr[k].sum = b[r];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(k);
}

int query1(int k, int p) {
    if (tr[k].l == tr[k].r) {
        return tr[k].sum;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) return query1(lson, p);
    return query1(rson, p);
}

void update(int k, int l, int r, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].tag = v;
        tr[k].sum = (tr[k].r - tr[k].l + 1) * v;
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) update(lson, l, r, v);
    if (r > mid) update(rson, l, r, v);
    up(k);
}

int query2(int k, int l, int r) {
    if (!tr[k].sum) return 0;
    if (tr[k].l == tr[k].r) {
        return tr[k].r;
    }
    down(k);
    int p = 0, mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) p = query2(lson, l, r);
    if (!p && r > mid) p = query2(rson, l, r);
    return p;
}

int query3(int k, int l, int r) {
    if (tr[k].sum == tr[k].r - tr[k].l + 1) return 0;
    if (tr[k].l == tr[k].r) {
        return tr[k].r;
    }
    down(k);
    int p = 0, mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) p = query3(lson, l, r);
    if (!p && r > mid) p = query3(rson, l, r);
    return p;
}

int query4(int k) {
    if (tr[k].l == tr[k].r) {
        return tr[k].r;
    }
    down(k);
    if (tr[rson].sum > 0) return query4(rson);
    return query4(lson);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[a[i]] += 1;
    }
    for (int i = 1; i <= t; ++i) {
        b[i + 1] += b[i] / 2;
        b[i] %= 2;
    }
    build(1, 1, t);
    while (m--) {
        cin >> k >> l;
        if (query1(1, a[k])) {
            update(1, a[k], a[k], 0);
        } else {
            int p = query2(1, a[k] + 1, t);
            update(1, a[k], p - 1, 1);
            update(1, p, p, 0);
        }
        a[k] = l;
        if (query1(1, a[k])) {
            int p = query3(1, a[k] + 1, t);
            update(1, a[k], p - 1, 0);
            update(1, p, p, 1);
        } else {
            update(1, a[k], a[k], 1);
        }
        cout << query4(1) << endl;
        // for (int i = 1; i <= n; ++i) {
        //     cout << a[i] << ' ';
        // }
        // cout << endl;
        // dfs(1);
        // cout << endl;
    }
    return 0;
}