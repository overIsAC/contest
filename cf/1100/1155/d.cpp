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
const int N = 3 + 3e5;

int n, a[N], x;
LL dp[N][2][2];

LL dfs(int p, int i, int j) {
    if (!p) {
        return 0;
    }
    if (dp[p][i][j] >= 0) {
        return dp[p][i][j];
    }
    LL ans = 0;
    ans = max(ans, dfs(p - 1, i, 0) + a[p]);
    if (!i || i && j) {
        ans = max(ans, dfs(p - 1, 1, 1) + (LL)a[p] * x);
    }
    return dp[p][i][j] = ans;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dfs(i, 0, 0));
    }
    cout << ans << endl;

    return 0;
}