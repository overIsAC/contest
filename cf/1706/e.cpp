#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m, q;

int fa[N];
vector<int> ve[N];
int d[N];
int f[N][20];
int lg[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        ve[i].clear();
        ve[i].push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        u = find(u);
        v = find(v);
        if (u == v)
            continue;
        if (ve[u].size() < ve[v].size()) {
            swap(u, v);
        }
        for (auto& j : ve[v]) {
            if (j > 1 && find(j - 1) == u)
                d[j] = i;
            if (j < n && find(j + 1) == u)
                d[j + 1] = i;
            ve[u].push_back(j);
        }
        fa[v] = u;
    }
    lg[0] = -1;
    for (int i = 1; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
        f[i][0] = d[i];
    }
    for (int j = 1; j < 20; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
    auto get = [&](int l, int r) {
        int t = lg[r - l + 1];
        return max(f[l][t], f[r - (1 << t) + 1][t]);
    };
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << ' ';
        } else {
            cout << get(l + 1, r) << ' ';
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}