#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int d[N], fa[N], son[N], sz[N];
vector<int> edge[N];
int top[N];

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (d[top[x]] < d[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if (d[x] > d[y]) swap(x, y);
    return x;
}

void dfs1(int x) {
    d[x] = d[fa[x]] + 1;
    sz[x] = 1;
    for (int &y : edge[x]) {
        if (d[y]) continue;
        fa[y] = x;
        dfs1(y);
        sz[x] += sz[y];
        if (sz[son[x]] < sz[y]) son[x] = y;
    }
}

void dfs2(int x, int topf) {
    top[x] = topf;
    if (son[x]) dfs2(son[x], topf);
    for (int &y : edge[x]) {
        if (top[y]) continue;
        dfs2(y, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(1);
    dfs2(1, 1);
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> a;
        while (k--) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int L = a[0];
        for (int i = 1; i < a.size(); ++i) {
            L = lca(L, a[i]);
        }
        sort(a.begin(), a.end(),
             [&](const int &a, const int &b) { return d[a] < d[b]; });
        vector<int> b;
        bool ok = true;
        for (auto &i : a) {
            int lc = lca(i, a.back());
            if (lc != i) {
                if (lc == L) {
                    b.push_back(i);
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && b.size()) {
            for (auto &i : b) {
                if (lca(i, b.back()) != i) {
                    ok = false;
                    break;  
                }
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}