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

int n, a[N], root[N], ls[N * 32], rs[N * 32], id;
LL sum[N * 32];
LL ans = 0;

void update(int u, int& v, int l, int r, int p, int value) {
    v = ++id;
    ls[v] = ls[u];
    rs[v] = rs[u];
    if (l == r) {
        sum[v] = sum[u] + value;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
        update(ls[u], ls[v], l, mid, p, value);
    } else {
        update(rs[u], rs[v], mid + 1, r, p, value);
    }
    sum[v] = sum[ls[v]] + sum[rs[v]];
}

LL query(int u, int v, int l, int r, int p) {
    if (p < l) {
        return 0;
    }
    if (r <= p) {
        return sum[v] - sum[u];
    }
    int mid = l + r >> 1;
    LL ans = 0;
    if (p >= l) {
        ans += query(ls[u], ls[v], l, mid, p);
    }
    if (p > mid) {
        ans += query(rs[u], rs[v], mid + 1, r, p);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!a[i]) {
            root[i] = root[i - 1];
        } else {
            update(root[i - 1], root[i], 1, 1e9, a[i], a[i]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        LL l, r, x;
        cin >> l >> r >> x;
        l ^= ans;
        r ^= ans;
        x ^= ans;

        ans = query(root[l - 1], root[r], 1, 1e9, x);

        cout << ans << endl;
    }

    return 0;
}