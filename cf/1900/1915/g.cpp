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
const int N = 3 + 1e3;

int d[N][N];
vector<PII> edge[N];
int n, m;
LL d2[N];
int vis[N];
LL s[N];

void bfs(int s, int* d) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        d[i] = 1e9;
    }
    q.push(s);
    d[s] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto [y, w] : edge[x]) {
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                q.push(y);
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
    }

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];

        bfs(i, d[i]);
        d2[i] = 1e18;
        vis[i] = 0;
    }


    priority_queue<pair<LL, int>> q;
    d2[1] = 0;
    q.push({0, 1});
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;
        for (int y = 1; y <= n; ++y) {
            if (d2[y] > d2[x] + d[x][y] * s[x]) {
                d2[y] = d2[x] + d[x][y] * s[x];
                q.push({-d2[y], y});
            }
        }
    }
    cout << d2[n] << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}