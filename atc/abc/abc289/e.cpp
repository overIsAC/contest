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
const int N = 3 + 2222;

int n, a[N], m;
vector<int> edge[N];
int d[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        edge[i].clear();
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    queue<PII> q;
    q.push({1, n});
    memset(d, 0x3f, sizeof(d));
    d[1][n] = 0;
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (auto &u : edge[x]) {
            for (auto &v : edge[y]) {
                if (d[u][v] > d[x][y] + 1 && a[u] != a[v]) {
                    d[u][v] = d[x][y] + 1;
                    q.push({u, v});
                }
            }
        }
    }
    if (d[n][1] > n * n) {
        cout << -1 << endl;
    } else {
        cout << d[n][1] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}