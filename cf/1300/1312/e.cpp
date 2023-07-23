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
const int N = 3 + 500;

int n, a[N];
int vis[N][N];
int dp[N];

void dfs(int l, int r) {
    if (vis[l][r] >= 0) {
        return;
    }
    if (l == r) {
        vis[l][r] = a[r];
        return;
    }
    dfs(l + 1, r);
    dfs(l, r - 1);
    if (vis[l + 1][r] == a[l]) {
        vis[l][r] = a[l] + 1;
    }
    if (vis[l][r - 1] == a[r]) {
        vis[l][r] = a[r] + 1;
    }
    for (int i = l; i < r; ++i) {
        dfs(l, i);
        dfs(i + 1, r);
        if (vis[l][i] && vis[l][i] == vis[i + 1][r]) {
            vis[l][r] = vis[l][i] + 1;
        }
    }
    if (vis[l][r] < 0) {
        vis[l][r] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(vis, -1, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dfs(i, j);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (vis[i][j] > 0) {
                dp[j] = min(dp[j], dp[i - 1] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}