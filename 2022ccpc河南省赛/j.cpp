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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, a[N];
vector<int> edge[N];
bool s[N];
int fa[N], p[N];
int sz[N];

void dfs(int x, int fa) {
    ::fa[x] = fa;
    sz[x] = 1;
    for (int &y : edge[x]) {
        if (y == fa) continue;
        dfs(y, x);
        sz[x] += sz[y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1, u, v; i < n; ++i) {
        u = i + 1;
        cin >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(p[0], 0);
    int ans = 0;
    for (int &y : edge[p[0]]) {
        ans = max(sz[y], ans);
    }
    cout << ans << ' ';
    for (int i = 1; i < n; ++i) {
        int px = fa[p[i]];
        while (px && !s[a[px]]) {
            s[a[px]] = true;
            px = fa[px];
        }
        if (s[i]) {
            cout << 0 << ' ';
        } else {
            cout << n - sz[p[i]] << ' ';
        }
    }
    cout << n << endl;

    return 0;
}