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
const int N = 3 + 2e5;

struct Node {
    int x, i;
};

int n, m, k;
vector<PII> edge[N];
bool pt[N];
deque<Node> q;
int d[N][2];
bool vis[N][2];

int main() {
    cin >> n >> m >> k;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    for (int i = 1; i <= k; ++i) {
        int p;
        cin >> p;
        pt[p] = true;
    }
    memset(d, 0x3f, sizeof(d));
    q.push_front({1, 0});
    d[1][0] = 0;
    while (q.size()) {
        int x = q.front().x, i = q.front().i;
        q.pop_front();
        if (vis[x][i]) {
            continue;
        }
        vis[x][i] = true;
        if (pt[x] && d[x][i ^ 1] > d[x][i]) {
            d[x][i ^ 1] = d[x][i];
            q.push_front({x, i ^ 1});
        }
        for (auto& j : edge[x]) {
            int y = j.first, w = j.second;
            if (w != i) {
                if (d[y][i] > d[x][i] + 1) {
                    d[y][i] = d[x][i] + 1;
                    q.push_back({y, i});
                }
            }
        }
    }
    int ans = min(d[n][0], d[n][1]);
    if (ans == 0x3f3f3f3f) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}