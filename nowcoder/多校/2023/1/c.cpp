#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int N = 3 + 1e6;
const int M = 3 + 2e5;

struct TreeNode {
    int l, r;
    LL minv, lazy;
} tr[M * 4];

vector<tuple<int, int, int>> ve[N];
int n, m, k;

void up(int k) {
    tr[k].minv = min(tr[lson].minv, tr[rson].minv);
}

void down(int k) {
    if (tr[k].lazy) {
        tr[lson].minv += tr[k].lazy;
        tr[rson].minv += tr[k].lazy;
        tr[lson].lazy += tr[k].lazy;
        tr[rson].lazy += tr[k].lazy;
        tr[k].lazy = 0;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int k, int l, int r, LL v) {
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
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            ve[l].push_back({1, i, x});
            ve[r + 1].push_back({1, i, -x});
        } else {
            ve[l].push_back({2, i, -k});
            ve[r + 1].push_back({2, i, k});
        }
    }
    build(1, 1, m);

    LL ans = 0;
    int d = 0; // 维护减的次数(不考虑多减情况)

    for (int i = 1; i <= n; ++i) {
        for (auto [op, t, v] : ve[i]) {
            update(1, t, m, v);
            if (op == 2) {
                if (v < 0) {
                    ++d;
                } else {
                    --d;
                }
            }
        }
        LL b = -min(0LL, tr[1].minv);
        b = (b + k - 1) / k; // 多减了b次

        ans += d - b;
    }

    cout << ans << endl;
    return 0;
}