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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 5e5;

int n, a[N];

struct TreeNode {
    int l, r;
    LL tag, sum;
};

struct SegmentTree {
    TreeNode tr[N << 2];

    void up(int k) {
        tr[k].sum = (tr[lson].sum + tr[rson].sum) % mod;
    }
    void down(int k) {
        if (tr[k].tag > 1) {
            tr[lson].tag = tr[lson].tag * tr[k].tag % mod;
            tr[lson].sum = tr[lson].sum * tr[k].tag % mod;
            tr[rson].tag = tr[rson].tag * tr[k].tag % mod;
            tr[rson].sum = tr[rson].sum * tr[k].tag % mod;
            tr[k].tag = 1;
        }
    }

    void build(int k, int l, int r) {
        tr[k].tag = 1;
        tr[k].sum = 0;
        tr[k].l = l;
        tr[k].r = r;
        if (l == r) {
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
    }
    void update(int k, int p, LL v) {
        if (tr[k].l == tr[k].r) {
            tr[k].sum = (tr[k].sum + v) % mod;
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
    void update(int k, int l, int r) {
        if (l <= tr[k].l && tr[k].r <= r) {
            tr[k].tag = tr[k].tag * 2 % mod;
            tr[k].sum = tr[k].sum * 2 % mod;
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
        up(k);
    }
    LL query(int k, int p) {
        if (tr[k].l == tr[k].r) {
            return tr[k].sum;
        }
        down(k);
        int mid = tr[k].l + tr[k].r >> 1;
        if (p <= mid) {
            return query(lson, p);
        } else {
            return query(rson, p);
        }
    }
    LL query(int k, int l, int r) {
        if (l <= tr[k].l && tr[k].r <= r) {
            return tr[k].sum;
        }
        down(k);
        int mid = tr[k].l + tr[k].r >> 1;
        LL ans = 0;
        if (l <= mid) {
            ans += query(lson, l, r);
        }
        if (r > mid) {
            ans += query(rson, l, r);
        }
        return ans % mod;
    }
    void update1(int p, LL v) {
        if (p < 0) {
            return;
        }
        update(1, p + 1, v);
    }
    void update2(int l, int r) {
        update(1, l + 1, r + 1);
    }
    LL query1(int p) {
        if (p < 0) {
            return 0;
        }
        return query(1, p + 1);
    }
    LL query2(int l, int r) {
        return query(1, l + 1, r + 1);
    }
} t1, t2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        t1.build(1, 1, n + 3);
        t2.build(1, 1, n + 3);
        LL ans = 0;

        for (int i = 1; i <= n; ++i) {
            int u1 = t1.query1(a[i]);
            int u2 = t1.query1(a[i] - 1);
            int u3 = t2.query1(a[i]);
            int u4 = t2.query1(a[i] - 1);
            if (!a[i]) {
                ans += t1.query2(0, n + 1);
                ans += t2.query2(0, n + 1);
            } else {
                ans += t1.query2(a[i] - 1, n + 1);
                ans += t2.query2(a[i] - 1, n + 1);
            }
            if (a[i] <= 1) {
                ++ans;
            }
            ans %= mod;

            t1.update2(a[i] + 1, n + 1);
            t2.update2(a[i] + 1, n + 1);
            if (a[i] == 0) {
                t1.update1(1, 1);
            } else if (a[i] == 1) {
                t2.update1(0, 1);
            }
            if (a[i] >= 1) {
                t1.update1(a[i] + 1, u1);
            }
            if (a[i] >= 1) {
                t2.update1(a[i] - 1, u2);
            }
            {
                t1.update1(a[i] + 2, u3);
            }
            if (a[i] >= 1) {
                t2.update1(a[i] - 1, u4);
            }
        }
        cout << ans << endl;
    }
    return 0;
}