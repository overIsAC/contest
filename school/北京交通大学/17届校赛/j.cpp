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
const int N = 3 + 2000;

int s, a, b, e, n, m;
vector<PII> edge[N];
bool vis[N][4];
int d[N][4];

struct Node {
    int x, st, d;
    bool operator<(const Node &other) const {
        return d > other.d;
    }
};

int getState(int p) {
    int ans = 0;
    if (p == a) ans |= 1;
    if (p == b) ans |= 2;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> a >> b >> e >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    priority_queue<Node> q;
    memset(d, 0x3f, sizeof(d));
    q.push({s, getState(s), 0});
    d[s][getState(s)] = 0;
    while (q.size()) {
        auto xx = q.top();
        q.pop();
        if (xx.st == 3 && xx.x == e) {
            cout << max(xx.d, 1800) << endl;
            return 0;
        }
        if (vis[xx.x][xx.st]) {
            continue;
        }
        vis[xx.x][xx.st] = 1;
        for (auto &e : edge[xx.x]) {
            int y = e.first, w = e.second;
            if (d[y][getState(y) | xx.st] > xx.d + w) {
                d[y][getState(y) | xx.st] = xx.d + w;
                q.push({y, getState(y) | xx.st, xx.d + w});
            }
        }
    }
    return 0;
}