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
const int N = 3 + 1e6;

struct TreeNode {
    int l, r;
    int minv, lazy;
} tr[N << 2];

int n, m;
array<int, 3> a[N * 3 / 10 + 1];

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    tr[k].minv = 0;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void down(int k) {
    if (tr[k].lazy) {
        tr[lson].minv += tr[k].lazy;
        tr[lson].lazy += tr[k].lazy;
        tr[rson].minv += tr[k].lazy;
        tr[rson].lazy += tr[k].lazy;
        tr[k].lazy = 0;
    }
}

void up(int k) {
    tr[k].minv = min(tr[lson].minv, tr[rson].minv);
}

void update(int k, int l, int r, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].minv += v;
        tr[k].lazy += v;
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
    up(k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a + 1, a + n + 1, [](array<int, 3> u, array<int, 3> v) {
        return u[2] < v[2];
    });
    build(1, 1, m - 1);
    int ans = INT_MAX;
    for (int i = 1, j = 1; i <= n; ++i) {
        auto [u, v, w1] = a[i];
        if (u > v - 1) {
            continue;
        }
        update(1, u, v - 1, 1);
        while (tr[1].minv > 0) {
            auto [u, v, w2] = a[j];
            ++j;
            if (u > v - 1) {
                continue;
            }
            update(1, u, v - 1, -1);
            ans = min(ans, w1 - w2);
        }
    }
    cout << ans << endl;
    return 0;
}