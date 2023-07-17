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
const int N = 3 + 1e5;

int n, k, z;
int a[N];
LL dp[N][8][2];

LL dfs(int p, int s, int l, int o) {
    if (s == k) {
        return 0;
    }
    if (dp[p][l][o] > 0) {
        return dp[p][l][o];
    }
    if (p < n) {
        dp[p][l][o] = max(dp[p][l][o], dfs(p + 1, s + 1, l, 0) + a[p + 1]);
    }
    if (p > 1 && l < z && !o) {
        dp[p][l][o] = max(dp[p][l][o], dfs(p - 1, s + 1, l + 1, 1) + a[p - 1]);
    }
    return dp[p][l][o];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k >> z;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            memset(dp[i], -0x3f, sizeof(dp[i]));
        }
        cout << dfs(1, 0, 0, 0) + a[1] << endl;
    }
    return 0;
}