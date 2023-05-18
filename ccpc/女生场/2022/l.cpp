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
const int N = 3 + 1e5;

int n, k;
int c[N];
map<int, int> mp[N];
vector<int> edge[N], ve[N];
int ans[N];
int f[N][20], d[N];
int q;

int fun(int x) {
    int kk = k + 1;
    for (int i = 19; i >= 0; --i) {
        if (kk >> i & 1) {
            x = f[x][i];
        }
    }
    return x;
}

void dfs(int x, int fa) {
    d[x] = d[fa] + 1;
    for (auto& y : edge[x]) {
        if (y == fa) {
            continue;
        }
        f[y][0] = x;
        for (int i = 1; i < 20; ++i) {
            f[y][i] = f[f[y][i - 1]][i - 1];
        }
        dfs(y, x);
        if (mp[x].size() < mp[y].size()) {
            swap(mp[x], mp[y]);
        }
        for (auto& v : mp[y]) {
            mp[x][v.first] += v.second;
        }
    }
    ++mp[x][c[x]];
    if (d[x] > k + 1) {
        ve[fun(x)].push_back(x);
    }
    for (auto& y : ve[x]) {
        if (!--mp[x][c[y]]) {
            mp[x].erase(c[y]);
        }
    }
    ans[x] = mp[x].size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}