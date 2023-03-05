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
const int N = 3 + 111;

int n, a[N];
LL dp[N][N];
int i, j, x, y;

LL dfs(int L, int R) {
    LL &ans = dp[L][R];
    if (~ans) {
        return ans;
    }
    ans = 0;
    if (L == R) {
        if (1 < L && L < n) {
            if (i == L) {
                if (x == 1) {
                    ans = 1;
                }
            } else if (j == L) {
                if (y == 1) {
                    ans = 1;
                }
            } else {
                ans = 1;
            }
        }
        return ans;
    }
    if (L == i && R - L + 1 == x) {
        ans += dfs(L + 1, R);
    } else if (L == j && R - L + 1 == y) {
        ans += dfs(L + 1, R);
    } else if (L != i && L != j) {
        ans += dfs(L + 1, R);
    }
    if (R == j && R - L + 1 == y) {
        ans += dfs(L, R - 1);
    } else if (R == i && R - L + 1 == x) {
        ans += dfs(L, R - 1);
    } else if (R != j && R != i) {
        ans += dfs(L, R - 1);
    }

    return ans % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> i >> j >> x >> y;
        x = n - x + 1;
        y = n - y + 1;
        cout << dfs(1, n) << endl;
    }
    return 0;
}