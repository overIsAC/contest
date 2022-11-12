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
const int N = 3 + 2e5;

int n, m, a[N];
int ls[N], rs[N];
int stk[N], top;
vector<int> dp[N];

void dfs(int x) {
    db(x);
    LL lsum = 0, rsum = 0;
    if (ls[x]) {
        dfs(ls[x]);
    } else {
        lsum = 1;
    }
    if (rs[x]) {
        dfs(rs[x]);
    } else {
        rsum = 1;
    }
    for (int i = 1; i <= m; ++i) {
        if (rs[x]) rsum = (rsum + dp[rs[x]][i]) % mod;
        dp[x][i] = lsum * rsum % mod;
        if (ls[x]) lsum = (lsum + dp[ls[x]][i]) % mod;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            ls[i] = rs[i] = 0;
            dp[i].clear();
            dp[i].resize(m + 1, 1);
        }
        int root = 0;
        top = 0;
        for (int i = 1; i <= n; ++i) {
            int old_top = top;
            while (top && a[stk[top]] < a[i]) {
                --top;
            }
            if (!top) {
                root = i;
            } else {
                rs[stk[top]] = i;
            }
            if (top < old_top) {
                ls[i] = stk[top + 1];
            }
            stk[++top] = i;
        }
        dfs(root);
        LL ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans += dp[root][i];
        }
        cout << ans % mod << endl;
    }
    return 0;
}