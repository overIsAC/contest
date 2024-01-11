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
const int N = 3 + 1e3;

int k, n, m;
int a[N];
vector<int> edge[N];
int cnt[N], vis[N];

void dfs(int x) {
    if (vis[x]) {
        return;
    }
    vis[x] = 1;
    ++cnt[x];
    for (auto& y : edge[x]) {
        dfs(y);
    }
}

int main() {
    cin >> k >> n >> m;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= k; ++i) {
        memset(vis, 0, sizeof(vis));
        dfs(a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == k) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}