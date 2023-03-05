#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int du[N];
vector<int> edge[N];
int n, m;
int d[N];
bool vis[N];
priority_queue<PII> q;

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[v].push_back(u);
        ++du[u];
    }
    q.push({0, n});
    memset(d, 0x3f, sizeof(d));
    d[n] = 0;
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int &y : edge[x]) {
            if (d[y] > d[x] + du[y]) {
                d[y] = d[x] + du[y];
                q.push({-d[y], y});
            }
            --du[y];
        }
    }
    cout << d[1] << endl;
    return 0;
}