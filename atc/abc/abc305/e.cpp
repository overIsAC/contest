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

int n, m, k;
vector<int> edge[N];
int d[N], vis[N];
priority_queue<PII> q;

int main() {
    cin >> n >> m >> k;
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(d, -1, sizeof(d));
    while (k--) {
        int p, h;
        cin >> p >> h;
        d[p] = max(d[p], h);
        q.push({d[p], p});
    }
    while (q.size()) {
        auto [_, x] = q.top();
        q.pop();
        if (vis[x] == 1) {
            continue;
        }
        vis[x] = 1;
        for (auto &y : edge[x]) {
            if (d[y] < d[x] - 1) {
                d[y] = d[x] - 1;
                q.push({d[y], y});
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (d[i] >= 0) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i << ' ';
    }
    return 0;
}