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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

struct TreeNode {
    int l, r;
    int ans, lv, rv;
    int lc, rc;
} tr[N << 2];

int n, q;

template <typename T>
void up(T &rt, const T &l, const T &r) {
    rt.l = l.l;
    rt.r = r.r;
    rt.ans = max(l.ans, r.ans);
    rt.lv = l.lv;
    rt.rv = r.rv;
    if (l.rv != r.lv) {
        rt.ans = max(rt.ans, l.rc + r.lc);
    }
    rt.lc = l.lc;
    if (l.r - l.l + 1 == l.lc && l.rv != r.lv) {
        rt.lc += r.lc;
    }
    rt.rc = r.rc;
    if (r.r - r.l + 1 == r.rc && l.rv != r.lv) {
        rt.rc += l.rc;
    }
}

void build(int k, int l, int r) {
    if (l == r) {
        tr[k].l = l;
        tr[k].r = r;
        tr[k].lc = tr[k].rc = tr[k].ans = 1;
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(tr[k], tr[lson], tr[rson]);
}

void update(int k, int p) {
    if (tr[k].l == tr[k].r) {
        tr[k].lv ^= 1;
        tr[k].rv ^= 1;
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) {
        update(lson, p);
    } else {
        update(rson, p);
    }
    up(tr[k], tr[lson], tr[rson]);
}

int main() {
    cin >> n >> q;
    build(1, 1, n);
    while (q--) {
        int p;
        cin >> p;
        update(1, p);
        cout << tr[1].ans << endl;
    }
    return 0;
}