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
const int N = 3 + 1000;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct Node {
    int x, y, dir;
};

map<char, int> dir;

int n, m;
int d[N][N][4];
int a[N][N];
int block[N][N];
char s;
int sx, sy, ex, ey;

int main() {
    dir['S'] = 0;
    dir['E'] = 1;
    dir['N'] = 2;
    dir['W'] = 3;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey >> s;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) {
                block[i][j] = 1;
                block[i - 1][j] = 1;
                block[i][j - 1] = 1;
                block[i - 1][j - 1] = 1;
            }
        }
    }

    memset(d, 0x3f, sizeof(d));
    d[sx][sy][dir[s]] = 0;
    queue<Node> q;
    q.push({sx, sy, dir[s]});

    while (q.size()) {
        auto z = q.front();
        q.pop();
        int x = z.x, y = z.y, dir = z.dir;

        // cout << x << ' ' << y << ' ' << dir << ' ' << d[x][y][dir] << endl;

        if (x == ex && y == ey) {
            cout << d[x][y][dir] << endl;
            return 0;
        }

        // 左右转头
        for (int i = -1; i <= 1; ++i) {
            int tdir = (dir + i + 4) % 4;
            if (d[x][y][tdir] > d[x][y][dir] + 1) {
                d[x][y][tdir] = d[x][y][dir] + 1;
                q.push({x, y, tdir});
            }
        }
        // 走几步
        for (int i = 1; i <= 3; ++i) {
            int tx = x + dx[dir] * i, ty = y + dy[dir] * i;
            if (0 < tx && tx < n && 0 < ty && ty < m) {
                if (block[tx][ty]) {
                    break;
                }
                if (d[tx][ty][dir] > d[x][y][dir] + 1) {
                    d[tx][ty][dir] = d[x][y][dir] + 1;
                    q.push({tx, ty, dir});
                }
            }
        }
    }
    cout << -1 << endl;

    return 0;
}