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
    // write node information

    int max;
};

TreeNode operator+(const TreeNode& l, const TreeNode& r) {
    TreeNode ans = {};
    ans.l = l.l;
    ans.r = r.r;
    // write merge node

    ans.max = max(l.max, r.max);

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
        node[k] = {};
        node[k].l = l;
        node[k].r = r;
        if (l == r) {
            // write init
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);

        node[k].max = max(node[lson].max, node[rson].max);
        // node[k] = node[lson] + node[rson];
    }

    // interval query
    int query(int k, int l, int r) {
        if (l <= node[k].l && node[k].r <= r) {
            return node[k].max;
        }
        down(k);
        int mid = node[k].l + node[k].r >> 1;
        // if (l <= mid && mid < r) {
        //     return query(lson, l, r) + query(rson, l, r);
        // }
        // if (l <= mid) {
        //     return query(lson, l, r);
        // }
        // return query(rson, l, r);

        int ans = 0;
        // 不包含整一个线段树节点的区间
        if (l <= mid) {
            ans = max(ans, query(lson, l, r));
        }
        if (r > mid) {
            ans = max(ans, query(rson, l, r));
        }
        return ans;
    }
    void update(int k, int p, int v) {
        // 更新一个点，不是更新区间
        // 把 p 这个位置改成 v
        if (node[k].l == node[k].r) {
            // 找到p这个位置，node[k].l == p && node[k].r == p
            node[k].max = max(node[k].max, v);
            return;
        }
        down(k);
        int mid = node[k].l + node[k].r >> 1;
        if (p <= mid) {
            update(lson, p, v);
        } else {
            update(rson, p, v);
        }
        node[k].max = max(node[lson].max, node[rson].max);
    }
} tr;

int main() {
    int n, d;
    cin >> n >> d;

    tr.build(1, 1, 5e5);

    while (n--) {
        int a;
        cin >> a;
        int l = max(1, a - d), r = min((int)5e5, a + d);
        int dp = 1 + tr.query(1, l, r);
        tr.update(1, a, dp);
    }
    cout << tr.query(1, 1, 5e5) << endl;
    return 0;
}