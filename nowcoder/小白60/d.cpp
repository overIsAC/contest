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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e3;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, x;
int sx, sy, ex, ey;
int d1[N][N], d2[N][N];
int a[N][N];

void bfs(int x, int y, int d[N][N]) {
    queue<PII> q;
    q.push({x, y});
    d[x][y] = 0;
    db("");
    while (q.size()) {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (1 <= tx && tx <= n && 1 <= ty && ty <= m && a[tx][ty] != -1) {
                if (d[tx][ty] > d[x][y] + 1) {
                    d[tx][ty] = d[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;
    cin >> sx >> sy >> ex >> ey;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));
    bfs(sx, sy, d1);
    bfs(ex, ey, d2);
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] > x) {
                db(d1[i][j] + d2[i][j]);
                ans = min(ans, d1[i][j] + d2[i][j]);
            }
        }
    }
    if (ans > n * m * 2) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}