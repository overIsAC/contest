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

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<array<int, 3>> edge(n - 1);
    for (auto &[u, v, w] : edge) {
        cin >> u >> v >> w;
        --u;
        --v;
    }
    sort(edge.begin(), edge.end(), [&](array<int, 3> &u, array<int, 3> &v) {
        return u[2] < v[2];
    });
    vector<LL> ans(m);
    vector<PII> query(m);
    for (int i = 0; i < m; ++i) {
        cin >> query[i].first;
        query[i].second = i;
    }
    sort(query.begin(), query.end());
    vector<int> fa(n);
    vector<int> sz(n);
    iota(fa.begin(), fa.end(), 0);
    fill(sz.begin(), sz.end(), 1);
    function<int(int)> find = [&](int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };
    int p = 0;
    LL now = 0;

    for (auto [w, id] : query) {
        while (p < edge.size() && edge[p][2] <= w) {
            auto [u, v, e] = edge[p];
            ++p;
            if (find(u) == find(v)) {
                continue;
            }
            now -= (LL)sz[find(u)] * (sz[find(u)] - 1) / 2;
            now -= (LL)sz[find(v)] * (sz[find(v)] - 1) / 2;
            sz[find(v)] += sz[find(u)];
            fa[find(u)] = find(v);
            now += (LL)sz[find(v)] * (sz[find(v)] - 1) / 2;
        }

        ans[id] = now;
    }
    for (auto &i : ans) {
        cout << i << ' ';
    }
    return 0;
}