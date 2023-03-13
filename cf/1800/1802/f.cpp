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
const int N = 3 + 800;

struct Node {
    int x, i;
    LL d;
    bool operator<(const Node &other) const {
        return d < other.d;
    }
};

vector<PII> edge[N];
int n, m, p;
LL d[N][N];
LL money[N][N];
int a[N];
bool vis[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        for (int i = 1; i <= n; ++i) {
            memset(d[i], 0x3f, sizeof(d[i]));
            memset(money[i], 0, sizeof(money[i]));
            cin >> a[i];
            edge[i].clear();
        }
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            edge[u].push_back({v, w});
        }
        queue<Node> q;
        d[1][1] = 0;
        money[1][1] = p;
        q.push({1, 1});
        while (q.size()) {
            auto xx = q.front();
            int x = xx.x, i = xx.i;
            q.pop();
            if (vis[x][i]) {
                continue;
            }
            vis[x][i] = 1;
            for (auto &e : edge[x]) {
                int w = e.second, y = e.first;
                if (money[x][i] - w >= 0) {
                    int j = i;
                    if (a[j] < a[y]) {
                        j = y;
                    }
                    if (d[y][j] > d[x][i]) {
                        d[y][j] = d[x][i];
                    }
                }
            }
        }
    }
    return 0;
}