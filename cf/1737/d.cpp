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

vector<PII> edge[N];
int n, m;
LL d[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            d[i] = 1e18;
            vis[i] = false;
        }
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            edge[u].push_back({v, w});
            edge[v].push_back({u, w});
        }
        priority_queue<PII> q;
        d[n] = 0;
        q.push({0, n});
        while (q.size()) {
            auto x = q.top().second;
            q.pop();
            if (vis[x]) continue;
            vis[x] = true;
            LL mn = 1e18;
            for (auto &e : edge[x]) {
                int &y = e.first, &w = e.second;
                mn = min(d[y], mn);
            }
            for (auto &e : edge[x]) {
                int &y = e.first, &w = e.second;
                if (d[y] > min(d[x] + w, mn + 2LL * w)) {
                    d[y] = min(d[x] + w, mn + 2LL * w);
                    q.push({-d[y], y});
                }
            }
        }
        for (int i= 1; i <= n; ++i) {
            cout << i << ' ' << d[i] << endl;
        }
        cout << d[1] << endl;
    }
    return 0;
}