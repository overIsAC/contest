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

int n, a[N], p, fa[N];
LL ans;

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

struct TreeNode {
    int l, r, gcd, min;
} tr[N << 2];

void up(int k) {
    tr[k].gcd = __gcd(tr[lson].gcd, tr[rson].gcd);
    tr[k].min = __gcd(tr[lson].min, tr[rson].min);
}

void build(int k, int l, int r) {
    tr[k].l = l;
    tr[k].r = r;
    if (l == r) {
        tr[k].gcd = tr[k].min = a[r];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(k);
}

int queryGcd(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k].gcd;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    int ans = 0;
    if (l <= mid) {
        ans = __gcd(queryGcd(lson, l, r), ans);
    }
    if (r > mid) {
        ans = __gcd(queryGcd(rson, l, r), ans);
    }
    return ans;
}

int queryMinPos(int l, int r) {
    if (l == r) {
        return r;
    }
    int v = queryMin(1, l, r), mid = l + r >> 1;
    if (queryMinPos(l, mid) == v) {
        return queryMinPos(l, mid);
    } else {
        queryMinPos(mid + 1, r);
    }
}

void dfs(int l, int r) {
    if (l >= r) {
        return;
    }
    int pos = queryMinPos(l, r);
    
}

int queryMin(int k, int l, int r) {
    if (l <= tr[k].l && tr[k].r <= r) {
        return tr[k].min;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    int ans = 2e9;
    if (l <= mid) {
        ans = min(queryMin(lson, l, r), ans);
    }
    if (r > mid) {
        ans = min(queryMin(rson, l, r), ans);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> p;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            fa[i] = i;
        }
        ans = 0;
        build(1, 1, n);
        dfs(1, n);
        for (int i = 1; i < n; ++i) {
            if (find(i) != find(i + 1)) {
                ans += p;
                fa[find(i)] = find(i + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}