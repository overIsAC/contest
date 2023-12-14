#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 3e5;

struct TreeNode {
    int l, r;
    LL a, b;
} tr[N << 2];

int n, a[N], b[N];

template <typename T>
void up(T& rt, const T& a, const T& b) {
    rt.a = a.a * b.a % mod;
    rt.b = (a.a * b.b + a.b) % mod;
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        tr[k].a = a[r];
        tr[k].b = b[r];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(tr[k], tr[lson], tr[rson]);
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

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int l, r, y;
        cin >> l >> r >> y;
        auto node = query(1, l, r);
        int a = node.a, b = node.b;
        if (a == 0) {
            if (b == y) {
                cout << "inf" << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }
        // ax + b == y
        LL ans = y - b;
        ans = ans * qpow(a, mod - 2) % mod;
        ans = (ans + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}