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
const int N = 3 + 100;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Node {
    int x, y, c, d;
    bool operator<(const Node& other) const {
        return d > other.d;
    }
};

int m, n;
int d[N][N][2];
int vis[N][N][2];
int col[N][N];
priority_queue<Node> q;

int main() {
    memset(col, -1, sizeof(col));

    cin >> m >> n;
    while (n--) {
        int x, y, c;
        cin >> x >> y >> c;
        col[x][y] = c;
    }
    memset(d, 0x3f, sizeof(d));

    d[1][1][col[1][1]] = 0;
    q.push({1, 1, col[1][1]});
    while (q.size()) {
        auto z = q.top();
        q.pop();
        int x = z.x, y = z.y, c = z.c;
        if (vis[x][y][c]) {
            continue;
        }
        vis[x][y][c] = 1;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (!(1 <= tx && tx <= m && 1 <= ty && ty <= m)) {
                continue;
            }
            if (col[tx][ty] == -1) {
                if (col[x][y] == -1) {
                    continue;
                }

                if (d[tx][ty][c] > d[x][y][c] + 2) {
                    d[tx][ty][c] = d[x][y][c] + 2;
                    q.push({tx, ty, c, d[tx][ty][c]});
                }
            } else {
                int w = 0;
                if (col[tx][ty] != c) {
                    w = 1;
                }
                if (d[tx][ty][col[tx][ty]] > d[x][y][c] + w) {
                    d[tx][ty][col[tx][ty]] = d[x][y][c] + w;
                    q.push({tx, ty, col[tx][ty], d[tx][ty][col[tx][ty]]});
                }
            }
        }
    }

    int ans = min(d[m][m][0], d[m][m][1]);
    if (ans > 1e9) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}