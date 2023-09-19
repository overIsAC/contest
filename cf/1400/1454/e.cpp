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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> edge(n);
    vector<int> du(n), d(n, 1);
    vector<int> vis(n);
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        ++du[u];
        ++du[v];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (du[i] == 1) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        vis[x] = 1;
        for (auto &y : edge[x]) {
            d[y] += d[x];
            if (--du[y] == 1) {
                q.push(y);
            }
        }
    }
    LL ans = 0;
    int t = n;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        int v = d[i];
        ans += (LL)v * (v - 1) / 2;
        ans += (LL)v * (t - v) * 2;
        t -= v;
    }
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