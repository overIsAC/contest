#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

vector<PII> edge[N];
int n;
LL ans;
int fa[N], sz[N], stk[N], top;

int find(int p) {
    while (fa[p] != p) p = fa[p];
    return p;
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    fa[u] = v;
    sz[v] += sz[u];
    stk[++top] = u;
}

void undo() {
    int x = stk[top--];
    sz[fa[x]] -= sz[x];
    fa[x] = x;
}

void dfs(int l, int r) {
    if (l == r) {
        for (auto i : edge[r]) {
            ans += (LL)sz[find(i.first)] * sz[find(i.second)];
        }
        return;
    }
    int old_top = top, mid = l + r >> 1;
    for (int i = mid + 1; i <= r; ++i) {
        for (auto &j : edge[i]) {
            merge(j.first, j.second);
        }
    }
    dfs(l, mid);
    while (top > old_top) undo();
    for (int i = l; i <= mid; ++i) {
        for (auto &j : edge[i]) {
            merge(j.first, j.second);
        }
    }
    dfs(mid + 1, r);
    while (top > old_top) undo();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        edge[w].push_back({v, u});
    }
    dfs(1, n);
    cout << ans << endl;
    return 0;
}