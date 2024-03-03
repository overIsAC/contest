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
int ls[N * 100], rs[N * 100], id, cnt[N * 100], root[N];
vector<int> edge[N];
LL ans;

void update(int& rt, int l, int r, int p, int v) {
    if (!rt) {
        rt = ++id;
    }
    if (l == r) {
        cnt[rt] = v;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
        update(ls[rt], l, mid, p, v);
    } else {
        update(rs[rt], mid + 1, r, p, v);
    }
    cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
}

int query(int& rt, int l, int r, int p) {
    if (!rt) {
        return 0;
    }
    if (l == r) {
        return cnt[rt];
    }
    int mid = l + r >> 1;
    if (p <= mid) {
        return query(ls[rt], l, mid, p);
    } else {
        return query(rs[rt], mid + 1, r, p);
    }
}

int merge(int u, int v, int l, int r) {
    if (!u || !v) {
        return u + v;
    }
    if (l == r) {
        ans += (LL)cnt[u] * cnt[v];
        int z = ++id;
        cnt[z] = cnt[u] + cnt[v];
        return z;
    }
    int z = ++id, mid = l + r >> 1;
    ls[z] = merge(ls[u], ls[v], l, mid);
    rs[z] = merge(rs[u], rs[v], mid + 1, r);
    cnt[z] = cnt[ls[z]] + cnt[rs[z]];
    return z;
}

void dfs(int x, int fa) {
    update(root[x], 1, n, a[x], 1);
    for (auto& y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        ans += query(root[y], 1, n, a[x]);
        update(root[y], 1, n, a[x], 0);
        root[x] = merge(root[x], root[y], 1, n);
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        root[i] = 0;
        edge[i].clear();
    }
    for (int i = 1; i <= id; ++i) {
        ls[i] = rs[i] = cnt[i] = 0;
    }
    ans = 0;

    id = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[v].push_back(u);
        edge[u].push_back(v);
    }

    dfs(1, 0);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}