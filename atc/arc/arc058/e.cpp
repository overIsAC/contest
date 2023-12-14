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
const int N = 3 + 1e5;

int n, x, y, z;
int dp[41][1 << 6][1 << 8][1 << 6][2];

int dfs(int p, int st1, int st2, int st3, int st4) {
    st1 &= (1 << x + 1) - 1;
    st2 &= (1 << y + 1) - 1;
    st3 &= (1 << z + 1) - 1;

    if (st3 >> z & 1) {
        st4 = 1;
    }
    if (st4) {
        st1 = st2 = st3 = 0;
    }
    if (p == 0) {
        return st4;
    }
    if (dp[p][st1][st2][st3][st4] >= 0) {
        return dp[p][st1][st2][st3][st4];
    }
    LL ans = 0;
    for (int i = 1; i <= 10; ++i) {
        ans += dfs(p - 1, (st1 << i) | (1 << i),
                   (st2 << i) | (((st1 >> x & 1) ? (1 << i) : 0)),
                   (st3 << i) | (((st2 >> y & 1) ? (1 << i) : 0)),
                   st4 || (st3 >> z & 1));
    }

    return dp[p][st1][st2][st3][st4] = ans % mod;
}

int main() {
    cin >> n >> x >> y >> z;
    memset(dp, -1, sizeof(dp));
    cout << dfs(n, 1, 0, 0, 0) << endl;
    return 0;
}