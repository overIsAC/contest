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
const int N = 3 + 1e5;

int fa[N];
int n;
vector<PII> edge[N];
PII e[N];
int id;
vector<int> seq;
int L[N], R[N];

struct TreeNode {
    int l, r;
    LL tag;
} tr[N << 2];

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

void update(int k, int l, int r, int v) {
    if (l <= tr[k].l && tr[k].r <= r) {
        tr[k].tag = (tr[k].tag + v) % mod;
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if (l <= mid) {
        update(lson, l, r, v);
    }
    if (r > mid) {
        update(rson, l, r, v);
    }
}

int query(int k, int p) {
    if (tr[k].l == tr[k].r) {
        return tr[k].tag;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    LL ans = tr[k].tag;
    if (p <= mid) {
        ans = (ans + query(lson, p)) % mod;
    } else {
        ans = (ans + query(rson, p)) % mod;
    }
    return ans;
}

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void dfs(int x) {
    L[x] = ++id;
    seq.push_back(x);
    for (auto [y, id] : edge[x]) {
        dfs(y);
    }
    R[x] = id;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int v, x;
            cin >> v >> x;
            e[++id] = {v, x};
            int y = find(v);
            edge[i].push_back({y, id});
            fa[y] = i;
        }
    }
    id = 0;
    for (int i = 1; i <= n; ++i) {
        if (find(i) != i) {
            continue;
        }
        dfs(i);
    }

    reverse(seq.begin(), seq.end());
    build(1, 1, n);
    LL ans = 0;
    for (auto &x : seq) {
        for (auto &[y, id] : edge[x]) {
            auto [v, x] = e[id];
            LL w = query(1, L[v]);
            w += x;
            w = (w % mod + mod) % mod;
            ans += w;
            update(1, L[y], R[y], w);
        }
    }
    cout << ans % mod << endl;
    return 0;
}