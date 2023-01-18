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
const int N = 3 + 1e3;

int n, m;
int a[N][N];
bool vis[N][N];
int dp[2][2][N];

bool valid1(int i, int j, int x, int y) {
    for (int k = 1; k <= m; ++k) {
        if (!vis[i][k]) {
            continue;
        }
        if ((!(x ^ y ^ a[i][k] ^ a[j][k]))) {
        } else {
            return false;
        }
    }
    return true;
}

bool valid(int i, int x, int y, int z) {
    for (int k = 1; k <= m; ++k) {
        if (!vis[i][k]) {
            continue;
        }
        if ((!(x ^ y ^ a[i - 1][k] ^ a[i][k]))) {
        } else if ((!(y ^ z ^ a[i + 1][k] ^ a[i][k]))) {
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int k = j;
            while (k + 1 <= m && a[i][k + 1] == a[i][k]) {
                ++k;
            }
            if (k == j) {
                vis[i][j] = true;
            }
            // cout << "   " << i << ' ' << j << ' ' << k << endl;
            j = k;
        }
    }

    memset(dp, 0x3f, sizeof(dp));

    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            if (valid1(1, 2, i, j)) {
                dp[i][j][2] = i + j;
            }
        }
    }

    for (int i = 2; i < n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                for (int q = 0; q <= 1; ++q) {
                    if (valid(i, j, k, q)) {
                        dp[k][q][i + 1] = min(dp[k][q][i + 1], dp[j][k][i] + q);
                        // cout << i << ' ' << j << ' ' << k << ' ' << q << endl;
                    }
                }
            }
        }
    }

    // cout << " dp " << dp[n][1][1] << endl;
    // cout << " vvv " << vis[3][1] << ' ' << vis[3][2] << ' ' << vis[3][3] << endl;

    int ans = 1e9;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            if (valid1(n, n - 1, i, j)) {
                // cout << i << ' '  << j << ' ' << dp[i][j][n] << endl;
                ans = min(ans, dp[i][j][n]);
            }
        }
    }
    if (n * 10 < ans) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}