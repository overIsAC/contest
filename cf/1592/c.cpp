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
const int N = 3 + 1e5;

int n, m, a[N];
vector<int> edge[N];
int sz[N];
int xo;
bool ok;

bool dfs(int x, int fa) {
    bool have = false;
    sz[x] = a[x];
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        bool flag = dfs(y, x);
        if (flag) {
            if (have) {
                ok = true;
            }
            have = true;
        }
        sz[x] ^= sz[y];
    }
    if (have && sz[x] == xo && fa) {
        ok = true;
    }
    if (sz[x] == xo) {
        have = true;
    }
    return have;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        xo = 0;
        for (int i = 1; i <= n; ++i) {
            xo ^= a[i];
        }
        if (xo == 0) {
            cout << "YES" << endl;
            continue;
        }
        ok = false;
        dfs(1, 0);
        if (ok && m - 1 >= 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}