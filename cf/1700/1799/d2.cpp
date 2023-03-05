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
const int N = 3 + 3e5;

int n, k, a[N], cold[N], hot[N];

struct {
    int l, r;
    LL val, lazy;
} tr[N * 4];

void down(int k) {
    //  db("");
    if (tr[k].lazy) {
        tr[lson].lazy += tr[k].lazy;
        tr[rson].lazy += tr[k].lazy;
        tr[lson].val += tr[k].lazy;
        tr[rson].val += tr[k].lazy;
        tr[lson].lazy = min<LL>(tr[lson].lazy, 1e18);
        tr[rson].lazy = min<LL>(tr[rson].lazy, 1e18);
        tr[lson].val = min<LL>(tr[lson].val, 1e18);
        tr[rson].val = min<LL>(tr[rson].val, 1e18);
        tr[k].lazy = 0;
    }
}

void up(int k) {
    //  db("");
    tr[k].val = min(tr[lson].val, tr[rson].val);
}

void build(int k, int l, int r) {
    tr[k] = {l, r, 0, 0};
    tr[k].val = 1e18;
    if (l == r) {
        if (l == 1) {
            tr[k].val = 0;
        }
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    if (l == 1) {
        tr[k].val = 0;
    }
}

LL query_point(int k, int p) {
    if (tr[k].l == tr[k].r) {
        return tr[k].val;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) {
        return query_point(lson, p);
    } else {
        return query_point(rson, p);
    }
}

LL query_interval(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k].val;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid && mid < r) {
        return min(query_interval(lson, l, r), query_interval(rson, l, r));
    }
    if (l <= mid) {
        return query_interval(lson, l, r);
    } else {
        return query_interval(rson, l, r);
    }
}

void update_point(int k, int p, LL v) {
    if (tr[k].l == tr[k].r) {
        tr[k].val = v;
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) {
        update_point(lson, p, v);
    } else {
        update_point(rson, p, v);
    }
    up(k);
}

void update_interval(int k, int l, int r, LL val) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].val += val;
        tr[k].lazy += val;
        tr[k].val = min<LL>(tr[k].val, 1e18);
        tr[k].lazy = min<LL>(tr[k].lazy, 1e18);
        return;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update_interval(lson, l, r, val);
    }
    if (r > mid) {
        update_interval(rson, l, r, val);
    }
    up(k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= k; ++i) {
            cin >> cold[i];
        }
        for (int i = 1; i <= k; ++i) {
            cin >> hot[i];
        }
        build(1, 1, k + 1);
        for (int i = 1; i <= n; ++i) {
            LL minv = query_point(1, a[i] + 1) + hot[a[i]];
            minv = min(query_interval(1, 1, a[i] - 1 + 1) + cold[a[i]], minv);
            if (a[i] + 1 <= k) {
                minv = min(query_interval(1, a[i] + 1 + 1, k + 1) + cold[a[i]], minv);
            }
            minv = min<LL>(minv, 1e18);
            // db(i);
            // db(a[i]);
            // db(query_interval(1, 1, a[i]));
            // db(query_interval(1, 1, k + 1));
            // db(minv);

            if (a[i] == a[i - 1]) {
                update_interval(1, 1, k + 1, hot[a[i]]);
            } else {
                update_interval(1, 1, k + 1, cold[a[i]]);
            }
            update_point(1, a[i - 1] + 1, minv);
        }
        cout << tr[1].val << '\n';
    }
    return 0;
}