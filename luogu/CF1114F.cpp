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
const int N = 3 + 4e5;

int n, q, a[N];

struct TreeNode {
    int l, r;
    // write node information
    int v;
};

TreeNode operator+(const TreeNode &l, const TreeNode &r) {
    TreeNode ans = {};
    ans.l = l.l;
    ans.r = r.r;
    // write merge node
    ans.v = l.v && r.v;
    return ans;
}

struct Tree {
    TreeNode node[N << 2];
    void build(int k, int l, int r) {
        node[k].l = l;
        node[k].r = r;
        if (l == r) {
            // write init
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
    }
    // interval query
    void down(int k) {
        if (node[k].v) {
            node[lson].v = 1;
            node[rson].v = 1;
        }
    }
    void up(int k) {
        node[k] = node[lson] + node[rson];
    }
    void update(int k, int l, int r) {
        if (l <= node[k].l && node[k].r <= r) {
            node[k].v = 1;
            return;
        }
        down(k);
        int mid = node[k].l + node[k].r >> 1;
        if (l <= mid) {
            update(lson, l, r);
        }
        if (r > mid) {
            update(rson, l, r);
        }
        up(k);
    }
    int query(int k, int l, int r) {
        if (node[k].v) {
            return 1;
        }
        if (l <= node[k].l && node[k].r <= r) {
            return node[k].v;
        }
        int mid = node[k].l + node[k].r >> 1;
        if (query(lson, l, r)) {
            return 1;
        }
        if (query(rson, l, r)) {
            return 1;
        }
        return 0;
    }
} tr[63];

Fenwick<LL, N> fw;
vector<int> ve[333];
int p[333], t;
LL inv[N];

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    inv[1] = 1;
    for (int i = 2; i <= 300; ++i) {
        if (ve[i].size()) {
            continue;
        }
        p[++t] = i;
        for (int j = i; j <= 300; j += i) {
            ve[j].push_back(t);
        }
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= 62; ++i) {
        tr[i].build(1, 1, n);
    }

    for (int i = 1; i <= n; ++i) {
        for (auto &j : ve[a[i]]) {
            tr[j].update(1, i, i);
        }
        fw.add(i, a[i]);
    }

    while (q--) {
        string op;
        int l, r, x;
        cin >> op >> l >> r;
        if (op == "MULTIPLY") {
            cin >> x;
        }
    }
    return 0;
}