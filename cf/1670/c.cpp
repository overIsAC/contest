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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], b[N], c[N];
bool vis[N];
vector<int> edge[N];

void dfs(int x) {
    vis[x] = true;
    for (int& y : edge[x]) {
        if (vis[y])
            continue;
        dfs(y);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
            edge[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            edge[a[i]].push_back(b[i]);
            edge[b[i]].push_back(a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[a[i]] || vis[b[i]])
                continue;
            if (a[i] == b[i]) {
                dfs(a[i]);
            }
            if (c[i]) {
                dfs(a[i]);
            }
        }
        LL ans = 1;
        for (int i = 1; i <= n; ++i) {
            if (vis[a[i]]) {
                continue;
            }
            dfs(a[i]);
            ans = ans * 2 % mod;
        }
        cout << ans << endl;
    }
    return 0;
}