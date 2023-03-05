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
const int N = 3 + 2e5;

vector<int> edge[N];
int n;
LL ans;

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int dfs(int x, int fa) {
    int d = 1;
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        d = max(d, dfs(y, x) + 1);
    }
    ans += qpow(2, n - 1) * d % mod;
    return d;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        ans = 0;
        dfs(1, 0);
        cout << ans % mod << endl;
    }
    return 0;
}