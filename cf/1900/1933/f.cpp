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

int n, m, a[N][N];
int d[N][N];
queue<PII> q;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = 1e9;
        }
    }
    q.push({0, 0});
    d[0][0] = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        int tx, ty;

        tx = (x + 1) % n;
        ty = (y + 1) % m;
        if (a[tx][ty] == 0) {
            if (d[tx][ty] > d[x][y] + 1) {
                d[tx][ty] = d[x][y] + 1;
                q.push({tx, ty});
            }
        }

        tx = (x + 2) % n;
        ty = (y + 0) % m;
        if (a[(x + 1) % n][y] == 0 && a[tx][ty] == 0) {
            if (d[tx][ty] > d[x][y] + 1) {
                d[tx][ty] = d[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        if (d[i][m - 1] >= 1e9) {
            continue;
        }
        int z = i - d[i][m - 1] % n;
        z = (z % n + n) % n;
        z = min(n - 1 - z, z + 1) + d[i][m - 1];
        ans = min(ans, z);
    }
    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}