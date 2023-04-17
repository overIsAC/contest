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
// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 3e5;

int n, m;
vector<int> edge[N];
int color[N];
int u[2];

bool dfs(int x, int col) {
    ++u[col];
    color[x] = col;
    for (auto &y : edge[x]) {
        if (color[y] >= 0) {
            if (color[x] + color[y] != 1) {
                return false;
            }
        } else {
            if (!dfs(y, 1 - col)) {
                return false;
            }
        }
    }
    return true;
}

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            color[i] = -1;
        }
        while (m--) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        LL ans = 1;
        for (int i = 1; i <= n; ++i) {
            if (color[i] >= 0) {
                continue;
            }
            memset(u, 0, sizeof(u));
            if (!dfs(i, 0)) {
                ans = 0;
                break;
            }
            ans = ans * (qpow(2, u[0]) + qpow(2, u[1])) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}