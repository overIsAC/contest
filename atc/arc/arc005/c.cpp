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
const int N = 3 + 555;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
char s[N][N];
int sx, sy, ex, ey;
int vis[N][N][4];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == 's') {
                sx = i;
                sy = j;
            }
            if (s[i][j] == 'g') {
                ex = i;
                ey = j;
            }
        }
    }
    queue<array<int, 3>> q;
    q.push({sx, sy, 0});
    while (q.size()) {
        auto [x, y, z] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (1 <= tx && tx <= n && 1 <= ty && ty <= m) {
                if (!vis[tx][ty][z] && s[tx][ty] != '#') {
                    vis[tx][ty][z] = 1;
                    q.push({tx, ty, z});
                }
                if (z + 1 <= 2 && !vis[tx][ty][z + 1] && s[tx][ty] == '#') {
                    vis[tx][ty][z + 1] = 1;
                    q.push({tx, ty, z + 1});
                }
            }
        }
    }
    if (vis[ex][ey][0] || vis[ex][ey][1] || vis[ex][ey][2]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl; 
    }
    return 0;
}