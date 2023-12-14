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
const int N = 3 + 2e5;

int n, t, k;
map<int, vector<int>> edge[N];
int d[N], vis[N];
priority_queue<PII> q;
vector<int> ve[N];
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= t; ++i) {
        int m;
        cin >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            edge[u][i].push_back(v);
            edge[v][i].push_back(u);
        }
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
        ve[a[i]].push_back(i);
    }

    q.push({0, 1});
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;
        for (auto &[t, e] : edge[x]) {
            auto p = upper_bound(ve[t].begin(), ve[t].end(), d[x]);
            if (p == ve[t].end()) {
                continue;
            }
            for (auto &y : e) {
                if (d[y] > *p) {
                    d[y] = *p;
                    q.push({-d[y], y});
                }
            }
        }
    }
    int ans = d[n];
    if (ans > 1e9) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}