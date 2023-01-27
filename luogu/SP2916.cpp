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

int n, m, a[N];

struct TreeNode {
    int l, r;
    LL sum, max, lmax, rmax;
};

TreeNode operator+(const TreeNode &l, const TreeNode &r) {
    TreeNode ans = {};
    ans.l = l.l;
    ans.r = r.r;
    ans.sum = l.sum + r.sum;
    ans.max = max({l.max, r.max, l.rmax + r.lmax});
    ans.lmax = max(l.lmax, l.sum + r.lmax);
    ans.rmax = max(r.rmax, r.sum + l.rmax);
    return ans;
}

struct Tree {
    TreeNode node[N << 2];
    void build(int k, int l, int r) {
        if (l == r) {
            node[k] = {l, r, a[r], a[r], a[r], a[r]};
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        node[k] = node[lson] + node[rson];
    }
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
} tr;

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
        tr.build(1, 1, n);

        cin >> m;
        while (m--) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            auto query = [&](int l, int r) {
                if (l > r) {
                    swap(l, r);
                }
                return tr.query(1, l, r);
            };
            if (r1 < l2) {
                LL ans = query(l1, r1).rmax + query(l2, r2).lmax;
                if (r1 + 1 <= l2 - 1) {
                    ans += query(r1 + 1, l2 - 1).sum;
                }
                cout << ans << endl;
            } else {
                LL ans = query(r1, l2).max;
                cout << ans << endl;
                if (l1 <= r1 - 1) {
                    ans = max(ans, query(l1, r1 - 1).rmax + query(r1, r2).lmax);
                }
                if (l2 + 1 <= r2) {
                    ans = max(ans, query(l1, l2).rmax + query(l2 + 1, r2).lmax);
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}