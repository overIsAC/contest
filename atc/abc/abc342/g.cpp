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

struct Node {
    int l, r;
    multiset<int> st;
} tr[N << 2];

int n, a[N];
int L[N], R[N], x[N], q;

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        // write init
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int k, int l, int r, int v, int add) {
    if (l <= tr[k].l && tr[k].r <= r) {
        if (add) {
            tr[k].st.insert(v);
        } else {
            tr[k].st.erase(tr[k].st.find(v));
        }
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update(lson, l, r, v, add);
    }
    if (r > mid) {
        update(rson, l, r, v, add);
    }
}

int query(int k, int p) {
    int ans = 0;
    if (tr[k].st.size()) {
        ans = max(ans, *tr[k].st.rbegin());
    }
    if (tr[k].l == tr[k].r) {
        return ans;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (p <= mid) {
        ans = max(query(lson, p), ans);
    } else {
        ans = max(query(rson, p), ans);
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
    build(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> L[i] >> R[i] >> x[i];
            update(1, L[i], R[i], x[i], 1);
        } else if (op == 2) {
            int j;
            cin >> j;
            update(1, L[j], R[j], x[j], 0);
        } else {
            int j;
            cin >> j;
            cout << max(a[j], query(1, j)) << endl;
        }
    }
    return 0;
}