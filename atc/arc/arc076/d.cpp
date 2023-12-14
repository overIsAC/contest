#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
int fa[N];

int find(int p) {
    return fa[p] == p ? p : fa[p] = find(fa[p]);
}

int main() {
    cin >> n;
    vector<array<int, 3>> a(n);
    int t = 0;
    for (auto& [u, v, id] : a) {
        cin >> u >> v;
        fa[t] = t;
        id = t++;
    }
    sort(a.begin(), a.end());
    vector<array<int, 3>> e;
    for (int i = 1; i < n; ++i) {
        e.push_back({a[i][0] - a[i - 1][0], a[i][2], a[i - 1][2]});
    }
    sort(a.begin(), a.end(),
         [](array<int, 3>& u, array<int, 3>& v) { return u[1] < v[1]; });
    for (int i = 1; i < n; ++i) {
        e.push_back({a[i][1] - a[i - 1][1], a[i][2], a[i - 1][2]});
    }

    sort(e.begin(), e.end());
    LL ans = 0;
    for (auto [w, u, v] : e) {
        u = find(u);
        v = find(v);
        if (u == v) {
            continue;
        }
        fa[u] = fa[v];
        ans += w;
    }
    cout << ans << endl;

    return 0;
}