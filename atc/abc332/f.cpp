#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using ULL = unsigned long long;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, q, a[N];

struct TreeNode {
    int l, r;
    LL a, b;
} tr[N << 2];

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        tr[k].b = a[r];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int k, int l, int r, int len, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update(lson, l, r, len, v);
    }
    if (r > mid) {
        update(rson, l, r, len, v);
    }
}
TreeNode query(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k];
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid && mid < r) {
        TreeNode ans;
        up(ans, query(lson, l, r), query(rson, l, r));
        return ans;
    }
    if (l <= mid) {
        return query(lson, l, r);
    } else {
        return query(rson, l, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    cin >> s + 1;

    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * 131 % mod;
    }

    build(1, 1, n);
    while (q--) {
        int op, l, r;
        int x;
        char c;
        cin >> op;
        if (op == 1) {
            cin >> x >> c;
            update(1, x, c);
        } else {
            cin >> l >> r;
            auto ans = query(1, l, r);
            if (ans.v1 == ans.v2) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}