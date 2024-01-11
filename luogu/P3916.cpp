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
const int N = 3 + 1e5;

int n, m;
vector<int> edge[N];
int d[N], vis[N];
priority_queue<PII> q;

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = i;
        q.push({d[i], i});
    }
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;
        for (auto& y : edge[x]) {
            if (d[y] < d[x]) {
                d[y] = d[x];
                q.push({d[y], y});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
    return 0;
}