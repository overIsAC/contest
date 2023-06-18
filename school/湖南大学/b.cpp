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

int n, a[N];
int L[N], R[N];
int root[N], mx[N * 40], ls[N * 40], rs[N * 40], id;

int query(int u, int l, int r, int p) {
    if (!u) {
        return 0;
    }
    if (p >= r) {
        return mx[u];
    }
    if (l == r) {
        return mx[u];
    }
    int mid = l + r >> 1;
    int ans = 0;
    if (p >= l) {
        ans = query(ls[u], l, mid, p);
    }
    if (p >= mid + 1) {
        ans = max(query(rs[u], mid + 1, r, p), ans);
    }
    return ans;
}

void update(int u, int &v, int l, int r, int p, int val) {
    v = ++id;
    mx[v] = max(mx[u], val);
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    ls[v] = ls[u];
    rs[v] = rs[u];
    if (p <= mid) {
        update(ls[u], ls[v], l, mid, p, val);
    } else {
        update(rs[u], rs[v], mid + 1, r, p, val);
    }
}


/*
3 
3  2 1
*/

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!L[a[i]]) {
            L[a[i]] = i;
        }
        R[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int p = a[i];
        if (R[p] == i) {
            int t = 1;
            if (p > 1) {
                t = max(t, query(root[L[p] - 1], 1, n, p - 1) + 1);
                update(root[i - 1], root[i], 1, n, p, t);
            } else {
                update(root[i - 1], root[i], 1, n, 1, 1);
            }
        } else {
            root[i] = root[i - 1];
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, mx[root[i]]);
    }
    ans = set<int>(a + 1, a + n + 1).size() - ans;
    cout << ans << endl;
    return 0;
}