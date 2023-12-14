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
    LL ord;
    LL set, add;
    int haveSet;
} tr[N * 4];

int n, a[N], q;
int l[N], r[N], x[N];
LL pre[N];

void up(int k) {
    if (tr[lson].ord) {
        tr[k].ord = tr[lson].ord;
    } else {
        tr[k].ord = tr[rson].ord;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    tr[k].ord = 0;
    tr[k].set = 0;
    tr[k].add = 0;
    tr[k].haveSet = 0;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void down(int k) {
    if (tr[k].haveSet) {
        tr[lson].set = tr[k].set;
        tr[lson].haveSet = 1;
        tr[lson].add = 0;
        tr[lson].ord = 0;

        tr[rson].set = tr[k].set;
        tr[rson].haveSet = 1;
        tr[rson].add = 0;
        tr[rson].ord = 0;

        tr[k].haveSet = 0;
    }

    if (tr[k].add) {
        tr[lson].ord += tr[k].add;
        if (tr[lson].haveSet) {
            tr[lson].set += tr[k].add;
        } else {
            tr[lson].add += tr[k].add;
        }

        tr[rson].ord += tr[k].add;
        if (tr[rson].haveSet) {
            tr[rson].set += tr[k].add;
        } else {
            tr[rson].add += tr[k].add;
        }

        tr[k].add = 0;
    }
}

void update(int k, int l, int r, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].ord += v;
        if (tr[k].haveSet) {
            tr[k].set += v;
        } else {
            tr[k].add += v;
        }
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update(lson, l, r, v);
    }
    if (r > mid) {
        update(rson, l, r, v);
    }
    up(k);
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
        update(1, l[i], r[i], x[i]);
        if (tr[1].ord < 0) {
            p = i;
            tr[1].set = 0;
            tr[1].haveSet = 1;
            tr[1].add = 0;
            tr[1].ord = 0;
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