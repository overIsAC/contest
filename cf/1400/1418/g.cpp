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
    int lazy, cnt, minv;
} tr[N * 4];

vector<int> ve[N];
int p[N];
int n, a[N];

void up(int k) {
    tr[k].minv = min(tr[lson].minv, tr[rson].minv);
    tr[k].cnt = 0;
    if (tr[k].minv == tr[lson].minv) {
        tr[k].cnt += tr[lson].cnt;
    }
    if (tr[k].minv == tr[rson].minv) {
        tr[k].cnt += tr[rson].cnt;
    }
}

void down(int k) {
    if (tr[k].lazy) {
        tr[lson].lazy += tr[k].lazy;
        tr[rson].lazy += tr[k].lazy;
        tr[lson].minv += tr[k].lazy;
        tr[rson].minv += tr[k].lazy;
        tr[k].lazy = 0;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        tr[k].cnt = 1;
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(k);
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

int query(int k, int l, int r) {
    if (tr[k].minv) {
        return 0;
    }
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k].cnt;
    }
    down(k);
    int mid = tr[k].l + tr[k].r >> 1;
    int ans = 0;
    if (l <= mid) {
        ans += query(lson, l, r);
    }
    if (r > mid) {
        ans += query(rson, l, r);
    }
    return ans;
}

void print(int k = 1) {
    cout << tr[k].l << ' ' << tr[k].r << ' ' << tr[k].cnt << ' ' << tr[k].minv << endl;
    if (tr[k].l == tr[k].r) {
        return;
    }
    down(k);
    print(lson);
    print(rson);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = ve[a[i]].size();
        ve[a[i]].push_back(i);
    }
    build(1, 1, n);
    /*
    p1, p2, p3, p4
    (p1,p2]
    */

    auto upd = [&](int idx, int v) {
        auto &vv = ve[a[idx]];
        update(1, 1, idx, v);
        if (p[idx] >= 2) {
            if (p[idx] >= 3) {
                update(1, vv[p[idx] - 3] + 1, vv[p[idx] - 2], -v);
            } else {
                update(1, 1, vv[p[idx] - 2], -v);
            }
        }
    };

    LL ans = 0;

    for (int i = 1; i <= n; ++i) {
        auto &vv = ve[a[i]];
        if (p[i] > 0) {
            upd(vv[p[i] - 1], -1);
        }
        upd(i, 1);
        ans += query(1, 1, i);

        // cout << "***************" << endl;
        // cout << i << endl;
        // print();
        // cout << "***************" << endl;

        // cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;

    return 0;
}