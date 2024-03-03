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
const int N = 3 + 2e5;

struct TreeNode {
    int l, r;
    // write node information
    int fir, sec, firCnt, secCnt;
};

int n, a[N], q;

TreeNode operator+(const TreeNode& l, const TreeNode& r) {
    TreeNode ans = {};
    ans.l = l.l;
    ans.r = r.r;
    // write merge node

    vector<PII> z;
    z.push_back({l.fir, l.firCnt});
    z.push_back({r.fir, r.firCnt});
    z.push_back({l.sec, l.secCnt});
    z.push_back({r.sec, r.secCnt});
    sort(z.begin(), z.end());
    tie(ans.fir, ans.firCnt) = z.back();
    z.pop_back();
    while (ans.fir == z.back().first) {
        ans.firCnt += z.back().second;
        z.pop_back();
    }
    if (z.size()) {
        tie(ans.sec, ans.secCnt) = z.back();
        z.pop_back();
        while (ans.sec == z.back().first) {
            ans.secCnt += z.back().second;
            z.pop_back();
        }
    } else {
        ans.sec = -1e9;
    }

    return ans;
}

struct Tree {
    TreeNode node[N << 2];
    void down(int k) {
        // write push down lazy tag
    }
    void up(int k) {
        node[k] = node[lson] + node[rson];
    }
    void build(int k, int l, int r) {
        if (l == r) {
            node[k].l = l;
            node[k].r = r;

            node[k].fir = a[r];
            node[k].firCnt = 1;
            node[k].sec = -1e9;
            // write init
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        node[k] = node[lson] + node[rson];
    }

    // interval query
    TreeNode query(int k, int l, int r) {
        if (l <= node[k].l && node[k].r <= r) {
            return node[k];
        }
        down(k);
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid && mid < r) {
            return query(lson, l, r) + query(rson, l, r);
        }
        if (l <= mid) {
            return query(lson, l, r);
        }
        return query(rson, l, r);
    }
    void update(int k, int p, int v) {
        if (node[k].l == node[k].r) {
            node[k].fir = v;
            return;
        }
        down(k);
        int mid = node[k].l + node[k].r >> 1;
        if (p <= mid) {
            update(lson, p, v);
        } else {
            update(rson, p, v);
        }
        up(k);
    }
    void update(int k, int l, int r, int v) {
        if (l <= node[k].l && node[k].r <= r) {
            return;
        }
        down(k);
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid) {
            update(lson, l, r, v);
        }
        if (r > mid) {
            update(rson, l, r, v);
        }
        up(k);
    }
} tr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    tr.build(1, 1, n);
    while (q--) {
        int op, p, x, l, r;
        cin >> op;
        if (op == 1) {
            cin >> p >> x;
            tr.update(1, p, x);
        } else {
            cin >> l >> r;
            cout << tr.query(1, l, r).secCnt << endl;
        }
    }

    return 0;
}