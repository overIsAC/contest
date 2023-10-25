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

int d[2][N], c[2][N];

void solve() {
    int n, m;
    int s, t;
    cin >> n >> m;
    cin >> s >> t;
    vector<vector<int>> edge(n + 1);

    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int i = 0; i <= n; ++i) {
        d[0][i] = d[1][i] = 1e9;
        c[0][i] = c[1][i] = 0;
    }
    queue<array<int, 3>> q;
    q.push({0, s, 0});
    d[0][s] = 0;
    c[0][s] = 1;
    while (q.size()) {
        auto [i, x, dd] = q.front();
        q.pop();
        if (d[i][x] != dd) {
            continue;
        }
        for (auto &y : edge[x]) {
            if (d[0][y] > d[i][x] + 1) {
                d[1][y] = d[0][y];
                c[1][y] = c[0][y];

                d[0][y] = d[i][x] + 1;
                c[0][y] = c[i][x];

                q.push({0, y, d[0][y]});
            } else if (d[0][y] == d[i][x] + 1) {
                (c[0][y] += c[i][x]) %= mod;
            } else if (d[1][y] > d[i][x] + 1) {
                d[1][y] = d[i][x] + 1;
                c[1][y] = c[i][x];

                q.push({1, y, d[1][y]});
            } else if (d[1][y] == d[i][x] + 1) {
                (c[1][y] += c[i][x]) %= mod;
            }
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << ' ' << d[0][i] << ' ' << d[1][i] << "   -   " << c[0][i] << ' ' << c[1][i] << endl;
    // }
    int ans = c[0][t];
    if (d[0][t] + 1 == d[1][t]) {
        ans += c[1][t];
        ans %= mod;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}