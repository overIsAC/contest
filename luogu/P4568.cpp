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

const int N = 10 + 1e4;

int n, m, k;
int s, t;
vector<pair<int, LL>> edge[N];

struct Node {
    LL d;
    int x, i;
    bool operator<(const Node &other) const {
        return d > other.d;
    }
};

priority_queue<Node> q;
LL d[N][11];  // d[x][i]表示，从起点s到点x用了i次免费的最短路
int vis[N][11];

void dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[s][0] = 0;
    q.push({0, s, 0});
    while (q.size()) {
        Node node = q.top();
        int x = node.x, i = node.i;
        q.pop();
        if (vis[x][i]) continue;
        vis[x][i] = 1;
        for (auto &e : edge[x]) {
            int y = e.first;
            LL w = e.second;
            if (d[y][i] > d[x][i] + w) {
                d[y][i] = d[x][i] + w;
                q.push({d[y][i], y, i});
            }
            if (i < k) {
                if (d[y][i + 1] > d[x][i]) {
                    d[y][i + 1] = d[x][i];
                    q.push({d[y][i + 1], y, i + 1});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    cin >> s >> t;
    while (m--) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dijkstra();
    LL ans = 1e18;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, d[t][i]);
    }
    cout << ans << endl;
    return 0;
}