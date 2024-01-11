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

int n, m, sx, sy;
char s[N][N];
queue<PII> q;
int d[N][N];

int main() {
    cin >> m >> n >> sy >> sx;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    sx = n - sx + 1;
    memset(d, 0x3f, sizeof(d));

    q.push({sx, sy});
    d[sx][sy] = 0;

    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int tx = dx + x, ty = dy + y;
                if (1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] == '.') {
                    if (d[tx][ty] > d[x][y] + 1) {
                        d[tx][ty] = d[x][y] + 1;
                        q.push({tx, ty});
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') {
                ans = max(ans, d[i][j]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}