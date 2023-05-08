#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e5;

int n, q, a[N];
int root[N], ls[N * 40], rs[N * 40], cnt[N * 40], id;

void update(int u, int &v, int l, int r, int p) {
    v = ++id;
    cnt[v] = cnt[u] + 1;
    if (l == r) {
        return;
    }
    ls[v] = ls[u];
    rs[v] = rs[u];
    int mid = l + r >> 1;
    if (p <= mid) {
        update(ls[u], ls[v], l, mid, p);
    } else {
        update(rs[u], rs[v], mid + 1, r, p);
    }
}

int query(int u, int v, int l, int r, int k) {
    if (cnt[v] - cnt[u] <= k) {
        return 0;
    }
    if (l == r) {
        return r;
    }
    int mid = l + r >> 1, ans = 0;
    ans = query(ls[u], ls[v], l, mid, k);
    if (!ans) {
        ans = query(rs[u], rs[v], mid + 1, r, k);
    }
    return ans;
}

int query2(int u, int v, int l, int r, int p) {
    if (l == r) {
        return cnt[v] - cnt[u];
    }
    int mid = l + r >> 1;
    if (p <= mid) {
        return query2(ls[u], ls[v], l, mid, p);
    } else {
        return query2(rs[u], rs[v], mid + 1, r, p);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        update(root[i - 1], root[i], 1, n, a[i]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int v = query(root[l - 1], root[r], 1, n, (r - l + 1) / 2);
        if (!v) {
            cout << 1 << endl;
            continue;
        }
        int cnt = query2(root[l - 1], root[r], 1, n, v);
        cout << max(1, abs(r - l + 1 - cnt - cnt)) << endl;
    }
    return 0;
}