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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;
vector<PII> edge[N];
map<int, set<int>> d[N];
queue<int> q;
int vis[N];

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    d[1][0].insert(0);
    q.push(1);

    auto push = [&](int y, int w, int z) -> int {
        if (d[y].size() == 0) {
            return d[y][z].insert(w).second;
        }
        if (d[y].begin()->first > z) {
            d[y].clear();
            d[y][z].insert(w);
            return 1;
        }
        if (d[y].begin()->first == z) {
            return d[y][z].insert(w).second;
        }
        return 0;
    };

    while (q.size()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (auto [y, w] : edge[x]) {
            for (auto &[u, v] : d[x]) {
                if (v.count(w)) {
                    if (push(y, w, u) && !vis[y]) {
                        vis[y] = 1;
                        q.push(y);
                    }
                } else {
                    if (push(y, w, u + 1) && !vis[y]) {
                        vis[y] = 1;
                        q.push(y);
                    }
                }
            }
        }
    }
    if (d[n].size()) {
        cout << d[n].begin()->first << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}