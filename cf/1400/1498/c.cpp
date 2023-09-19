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
const int N = 3 + 1e3;

LL dp[N][N][2];
int vis[N][N][2];

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<array<int, 3>> q;
    for (int i = 0; i <= k + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            dp[i][j][0] = dp[i][j][1] = 0;
            vis[i][j][0] = vis[i][j][1] = 0;
        }
    }

    auto add = [&](LL a, LL& b) {
        b += a;
        b %= mod;
    };
    auto push = [&](int x, int y, int z) {
        // cout << x << ' ' << y << ' ' << z << endl;
        if (vis[x][y][z]) {
            return;
        }
        q.push({x, y, z});
        vis[x][y][z] = 1;
    };
    push(k, 1, 1);
    dp[k][1][1] = 1;

    while (q.size()) {
        auto [x, y, z] = q.top();
        q.pop();
        if (z == 1) {
            if (y == n + 1) {
                continue;
            }
            if (y + 1 <= n + 1) {
                add(dp[x][y][z], dp[x][y + 1][z]);
                push(x, y + 1, z);
            }
            if (x > 1) {
                add(dp[x][y][z], dp[x - 1][y][0]);
                push(x - 1, y, 0);
            }
        } else {
            if (y == 1) {
                continue;
            }
            if (y - 1 >= 1) {
                add(dp[x][y][z], dp[x][y - 1][z]);
                push(x, y - 1, z);
            }
            if (x > 1) {
                add(dp[x][y][z], dp[x - 1][y][1]);
                push(x - 1, y, 1);
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += dp[i][1][0];
        ans += dp[i][n + 1][1];
    }
    ans %= mod;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}