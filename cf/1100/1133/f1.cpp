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

int fa[N];
int u[N], v[N];
set<int> st[N];
int n, m;

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i];
        st[u[i]].insert(v[i]);
        st[v[i]].insert(u[i]);
    }
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        if (st[p].size() < st[i].size()) {
            p = i;
        }
    }
    vector<PII> ans;
    for (int i = 1; i <= m; ++i) {
        if (u[i] == p || v[i] == p) {
            if (find(u[i]) == find(v[i])) {
                continue;
            }
            fa[find(u[i])] = v[i];
            ans.push_back({u[i], v[i]});
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (find(u[i]) == find(v[i])) {
            continue;
        }
        fa[find(u[i])] = v[i];
        ans.push_back({u[i], v[i]});
    }
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
    }
    return 0;
}