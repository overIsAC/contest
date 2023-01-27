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

struct TreeNode {
    int l, r;
    LL val;
};

TreeNode operator+(const TreeNode &l, const TreeNode &r) {
    TreeNode ans = {};
    ans.l = l.l;
    ans.r = r.r;
    ans.val = l.val + r.val;
    return ans;
}

struct Tree {
    TreeNode node[N << 3];
    void up(int k) {
        node[k] = node[lson] + node[rson];
    }
    void build(int k, int l, int r) {
        node[k] = {l, r, 0};
        if (l == r) {
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
    }

    // interval query
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
    void update(int k, int p, LL v) {
        if (node[k].l == node[k].r) {
            node[k].val += v;
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
} tr1, tr2;

struct Query {
    int type, p, x;
    LL v;
} query[N];

int n, m, a[N];
LL b[N * 2], t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[++t] = a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> query[i].type;
        if (query[i].type == 1) {
            cin >> query[i].p >> query[i].x;
            b[++t] = query[i].x;
        } else {
            cin >> query[i].v;
        }
    }
    sort(b + 1, b + t + 1);
    t = unique(b + 1, b + t + 1) - b - 1;
    tr1.build(1, 1, t);
    tr2.build(1, 1, t);
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(b + 1, b + t + 1, a[i]) - b;
        tr1.update(1, a[i], b[a[i]]);
        tr2.update(1, a[i], 1);
    }
    for (int i = 1; i <= m; ++i) {
        if (query[i].type == 1) {
            int x = lower_bound(b + 1, b + t + 1, query[i].x) - b;
            int p = query[i].p;
            tr1.update(1, a[p], -b[a[p]]);
            tr2.update(1, a[p], -1);
            tr1.update(1, x, b[x]);
            tr2.update(1, x, 1);
            a[p] = x;
        } else {
            LL o = query[i].v;
            auto ok = [&](long double x) -> bool {
                int l = 1, r = t;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (b[mid] <= x) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                LL u = tr1.query(1, 1, r).val, v = tr2.query(1, 1, r).val;
                return v * x >= u + o;
            };
            long double L = 0, R = 1e16;
            while (R - L > 1e-6) {
                auto mid = (L + R) / 2;
                if (ok(mid)) {
                    R = mid;
                } else {
                    L = mid;
                }
            }
            cout << fixed << setprecision(8) << R << '\n';
        }
    }
    return 0;
}