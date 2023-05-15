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
const int N = 3 + 2e5;

int n, k;
vector<int> edge[N];
int sz[N];
LL ans;

void dfs(int x, int fa) {
    sz[x] = 1;
    for (auto &y : edge[x]) {
        if (fa == y) {
            continue;
        }
        dfs(y, x);
        sz[x] += sz[y];
        ans += (LL)sz[y] * (n - sz[y] - 1);
    }
    ans += (LL)(sz[x] - 1) * (n - sz[x]);
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
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    if (k == 1 || k == 3) {
        cout << 1 << endl;
        return 0;
    }
    dfs(1, 0);
    ans /= 2;
    ans += (LL)n * (n - 1);
    ans %= mod;
    ans = ans * qpow((LL)n * (n - 1) / 2 % mod, mod - 2) % mod;
    cout << ans << endl;
    return 0;
}