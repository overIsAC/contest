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

int n, m, a[N];
vector<int> edge[N];
int fa[N];
int d[N];
set<int> st[N];
vector<int> seq[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void merge(int x, int y) {
    int u = find(x), v = find(y);
    if (u == v) {
        return;
    }
    if (st[u].size() < st[v].size()) {
        swap(u, v);
    }
    for (auto& w : st[v]) {
        st[u].insert(w);
    }
    fa[v] = u;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        st[i].insert(i);
        seq[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : edge[i]) {
            if (a[i] == a[j]) {
                merge(i, j);
            }
        }
    }
    memset(d, -0x3f, sizeof(d));
    d[find(1)] = 1;
    for (int i = 1; i <= 2e5; ++i) {
        for (auto& x : seq[i]) {
            for (auto& y : edge[x]) {
                if (a[y] <= a[x]) {
                    continue;
                }
                if (d[find(y)] < d[find(x)] + 1) {
                    d[find(y)] = d[find(x)] + 1;
                }
            }
        }
    }
    int ans = d[find(n)];
    if (ans < 0) {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}