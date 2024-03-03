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
const int N = 3 + 2e3;

int n, m;
char s[N][N];
int block[N][N];
int sx, sy, ex, ey;
int d[N][N];

int check(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (s[i][j] == 'G') {
                ex = i;
                ey = j;
            }
            if (s[i][j] == '<') {
                int x = i, y = j - 1;
                while (y >= 1 && s[x][y] == '.') {
                    block[x][y] = 1;
                    --y;
                }
            }
            if (s[i][j] == '>') {
                int x = i, y = j + 1;
                while (y <= m && s[x][y] == '.') {
                    block[x][y] = 1;
                    ++y;
                }
            }
            if (s[i][j] == '^') {
                int x = i - 1, y = j;
                while (x >= 1 && s[x][y] == '.') {
                    block[x][y] = 1;
                    --x;
                }
            }
            if (s[i][j] == 'v') {
                int x = i + 1, y = j;
                while (x <= n && s[x][y] == '.') {
                    block[x][y] = 1;
                    ++x;
                }
            }
        }
    }
    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};
    queue<PII> q;
    q.push({sx, sy});
    memset(d, 0x3f, sizeof(d));
    d[sx][sy] = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (check(tx, ty) && !block[tx][ty]) {
                if (s[tx][ty] == '#') {
                    continue;
                }
                if (s[tx][ty] == '^') {
                    continue;
                }
                if (s[tx][ty] == 'v') {
                    continue;
                }
                if (s[tx][ty] == '<') {
                    continue;
                }
                if (s[tx][ty] == '>') {
                    continue;
                }
                if (d[tx][ty] > d[x][y] + 1) {
                    d[tx][ty] = d[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }
    int ans = d[ex][ey];
    if (ans > 1e9) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}