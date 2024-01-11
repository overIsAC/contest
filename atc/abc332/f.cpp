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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int n, q, a[N];
LL inv[N];

struct TreeNode {
    int l, r;
    LL a, b;
} tr[N << 2];

void down(int k) {
    tr[lson].a = tr[lson].a * tr[k].a % mod;
    tr[lson].b = tr[lson].b * tr[k].a % mod;
    tr[lson].b = (tr[lson].b + tr[k].b) % mod;

    tr[rson].a = tr[rson].a * tr[k].a % mod;
    tr[rson].b = tr[rson].b * tr[k].a % mod;
    tr[rson].b = (tr[rson].b + tr[k].b) % mod;

    tr[k].a = 1;
    tr[k].b = 0;
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    tr[k].a = 1;
    if (l == r) {
        tr[k].b = a[r];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int k, int l, int r, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].a = tr[k].a * inv[r - l + 1] % mod * (r - l) % mod;
        tr[k].b = tr[k].b * inv[r - l + 1] % mod * (r - l) % mod;
        tr[k].b = (tr[k].b + (LL)v * inv[r - l + 1]) % mod;
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
}
void print(int k) {
    if (tr[k].l == tr[k].r) {
        cout << tr[k].b << ' ';
        return;
    }
    down(k);
    print(lson);
    print(rson);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }

    build(1, 1, n);
    while (q--) {
        int l, r, v;
        cin >> l >> r >> v;
        update(1, l, r, v);
    }
    print(1);
    return 0;
}