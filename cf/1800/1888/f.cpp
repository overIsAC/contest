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

struct TreeNode {
    int l, r;
    int zero, set;
    LL v;
} tr[N * 4];

int n, a[N], q;
int l[N], r[N], x[N];
LL pre[N];

void up(int k) {
    tr[k].zero = tr[lson].zero + tr[rson].zero;
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    tr[k].zero = r - l + 1;
    tr[k].set = 0;
    tr[k].v = 0;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void add(TreeNode &rt) {
    rt.zero = rt.r - rt.l + 1;
    rt.set = 1;
    rt.v = 0;
}

void down(int k) {
    if (tr[k].set) {
        add(tr[lson]);
        add(tr[rson]);

        tr[k].set = 0;
    }
}

void update(int k, int p, int v) {
    if (tr[k].l == tr[k].r) {
        tr[k].v += v;
        tr[k].zero = tr[k].v == 0;
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) {
        update(lson, p, v);
    } else {
        update(rson, p, v);
    }
    up(k);
}

int query(int k) {
    if (tr[k].l == tr[k].r) {
        return tr[k].v < 0;
    }
    if (tr[lson].zero < tr[lson].r - tr[lson].l + 1) {
        return query(lson);
    } else {
        return query(rson);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> l[i] >> r[i] >> x[i];
    }
    build(1, 1, n);

    int p = 0;

    for (int i = 1; i <= q; ++i) {
        update(1, l[i], x[i]);
        if (r[i] < n) {
            update(1, r[i] + 1, -x[i]);
        }
        if (query(1)) {
            p = i;
            add(tr[1]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] = 0;
    }
    for (int i = 1; i <= p; ++i) {
        pre[l[i]] += x[i];
        pre[r[i] + 1] -= x[i];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        cout << pre[i] + a[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}