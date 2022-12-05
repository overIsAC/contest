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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 500;

struct Node {
    LL d;
    int x, i;
    bool operator<(const Node& w) const { return d > w.d; }
};

vector<PII> edge[N];
int n, m, q;
int w[N], t;
LL d[N][N];
bool vis[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    memset(d, 0x3f, sizeof(d));
    priority_queue<Node> que;
    que.push({0LL, 1, 0});
    d[1][0] = 0;
    while (que.size()) {
        int x = que.top().x, i = que.top().i;
        que.pop();
        if (vis[x][i]) {
            continue;
        }
        vis[x][i] = true;
        for (auto& e : edge[x]) {
            int y = e.first, w = e.second;
            if (d[y][i + 1] > d[x][i] + w) {
                d[y][i + 1] = d[x][i] + w;
                if (i + 1 < n) {
                    que.push({d[y][i + 1], y, i + 1});
                }
            }
        }
    }
    cin >> q;
    while (q--) {
        cin >> t;
        for (int i = 1; i <= n - 1; ++i) {
            cin >> w[i];
        }
        LL ans = d[t][0];
        LL pre = 0;
        for (int i = 1; i <= n - 1; ++i) {
            pre += w[i];
            ans = min(ans, d[t][i] + pre);
        }
        cout << ans << endl;
    }

    return 0;
}