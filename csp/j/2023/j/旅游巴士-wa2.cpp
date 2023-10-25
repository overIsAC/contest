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
const int N = 3 + 1e4;

int n, m, k;
vector<PII> edge[N];
int d[N][103];
int vis[N][103];

struct Node {
    int x, d, i;
    bool operator<(const Node &other) const {
        return d > other.d;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    while (m--) {
        int u, v, a;
        cin >> u >> v >> a;
        edge[u].push_back({v, a});
    }
    memset(d, 0x3f, sizeof(d));
    priority_queue<Node> q;
    q.push({1, 0, 0});
    d[1][0] = 0;
    while (q.size()) {
        auto node = q.top();
        q.pop();

        int x = node.x, i = node.i;

        if (vis[x][i]) {
            continue;
        }

        vis[x][i] = 1;

        for (auto &e : edge[x]) {
            int y = e.first, a = e.second;
            if (d[x][i] >= a) {
                int j = (d[x][i] + 1) % k;
                if (d[y][j] > d[x][i] + 1) {
                    d[y][j] = d[x][i] + 1;
                    q.push({y, d[y][j], j});
                }
            } else {
                if (d[x][i] >= 1) {                 // 有前驱
                    int t = (a - d[x][i] + 1) / 2;  // 反复横跳次数
                    int w = t * 2 + 1;
                    int j = (d[x][i] + w) % k;
                    if (d[y][j] > d[x][i] + w) {
                        d[y][j] = d[x][i] + w;
                        q.push({y, d[y][j], j});
                    }
                }
            }
        }
    }

    int ans = d[n][0];
    if (ans > 1e9) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}