#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

vector<int> edge[N];
int n, m;
int sz[N];
LL cnt[N][2], d[N][2];
int a[N];

void dfs1(int x, int fa) {
    sz[x] = 1;
    for (int &y : edge[x]) {
        if (y == fa) continue;
        dfs1(y, x);
        sz[x] += sz[y];
    }
}

void dfs2(int x, int fa) {
    int v = x;
    while (v % 2 == 0) {
        v /= 2;
        ++d[x][0];
    }
    while (v % 5 == 0) {
        v /= 5;
        ++d[x][1];
    }
    for (int &y : edge[x]) {
        if (y == fa) continue;
        cnt[y][0] = cnt[x][0] + (sz[x] - sz[y]) * d[x][0];
        cnt[y][1] = cnt[x][1] + (sz[x] - sz[y]) * d[x][1];
        dfs2(y, x);
    }
    cnt[x][0] += d[x][0] * sz[x];
    cnt[x][1] += d[x][1] * sz[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    while (m--) {
        int x = 0;
        cin >> x;
        cout << min(cnt[x][0], cnt[x][1]) << endl;
    }
    return 0;
}