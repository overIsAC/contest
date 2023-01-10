#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

struct Node {
    LL d;
    int x, i, j;
    bool operator<(const Node& u) const {
        return d > u.d;
    }
};

LL d[N][2][55];
bool vis[N][2][55];
vector<PII> e[N];
int n, m;

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    memset(d, 0x3f, sizeof(d));
    priority_queue<Node> q;
    q.push({0, 1, 0, 0});
    d[1][0][0] = 0;
    while (q.size()) {
        int x = q.top().x, i = q.top().i, j = q.top().j;
        q.pop();
        if (vis[x][i][j]) {
            continue;
        }
        vis[x][i][j] = true;
        for (auto& ee : e[x]) {
            int& y = ee.first;
            int& w = ee.second;
            if (i == 0) {
                if (d[y][1][w] > d[x][0][0]) {
                    d[y][1][w] = d[x][0][0];
                    q.push({d[y][1][w], y, 1, w});
                }
            } else {
                if (d[y][0][0] > d[x][1][j] + (w + j) * (w + j)) {
                    d[y][0][0] = d[x][1][j] + (w + j) * (w + j);
                    q.push({d[y][0][0], y, 0, 0});
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (d[i][0][0] > 1e15) {
            d[i][0][0] = -1;
        }
        cout << d[i][0][0] << ' ';
    }

    return 0;
}