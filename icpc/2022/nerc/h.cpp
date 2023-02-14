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
const int N = 3 + 2000;

int n, m, pos[N];
vector<int> edge[N];
vector<int> edge2[N];
vector<int> ve[N];
int ans[N];
int u[N], v[N];
bitset<N> d[N];
int du[N];
int vis[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i];
        edge[u[i]].push_back(v[i]);
        du[v[i]] += 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        d[i][i] = 1;
        if (!du[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto &y : edge[x]) {
            d[y] |= d[x];
            pos[x] = min(pos[x], pos[y] - 1);
            if (!--du[y]) {
                q.push(y);
            }
        }
    }
    // cout << endl;
    for (int i = 1; i <= n; ++i) {
        // cout << i << ' ' << pos[i] << endl;
        ve[pos[i]].push_back(i);
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << i << ' ' << pos[i] << endl;
    // }

    int sum = 0;
    vis[1] = 1;
    for (int i = 1; i <= n; ++i) {
        sum += ve[i].size();
        if (sum == i) {
            vis[i + 1] = i + 1;
        } else {
            vis[i + 1] = vis[i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << max<int>(d[i].size(), vis[pos[i]]) << ' ';
    }

    return 0;
}