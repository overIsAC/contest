#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n, q;
    cin >> n;
    vector<int> d(n + 1);
    vector<int> fa(n + 1);
    vector<vector<int>> edge(n + 1);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int x, int f) {
        d[x] = d[f] + 1;
        fa[x] = f;
        for (auto &y : edge[x]) {
            if (f == y) continue;
            dfs(y, x);
        }
    };
    auto get = [&](int x, int y) {
        set<int> s;
        while (x != y) {
            if (d[x] > d[y]) {
                s.insert(x);
                x = fa[x];
            } else {
                s.insert(y);
                y = fa[y];
            }
        }
        s.insert(x);
        return s;
    };
    dfs(1, 0);
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> ve(k);
        for (auto &i : ve) {
            cin >> i;
        }
        if (ve.size() == 1) {
            cout << "YES" << endl;
            continue;
        }
        sort(ve.rbegin(), ve.rend(),
             [&](const int &a, const int &b) { return d[a] < d[b]; });
        auto s = get(ve[0], ve[1]);
        bool ok = true;
        for (auto &i : ve) {
            if (!s.count(i)) {
                ok = false;
                break;
            }
        }
        s = get(ve[0], ve.back());
        for (auto &i : ve) {
            if (!s.count(i)) {
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}