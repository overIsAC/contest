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
int vis[N];

void dfs(int x) {
    if (vis[x]) {
        return;
    }
    vis[x] = 1;
    cout << x << ' ';
    for (auto& y : edge[x]) {
        dfs(y);
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(1);
    cout << endl;

    memset(vis, 0, sizeof(vis));

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (auto& y : edge[x]) {
            if (vis[y]) {
                continue;
            }
            q.push(y);
            vis[y] = 1;
        }
    }
    return 0;
}