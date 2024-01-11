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
const int N = 3 + 300;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
char s[N][N];
int d[N][N];
PII trans[N][N];

vector<PII> ve[256];
int sx, sy, ex, ey;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
        for (int j = 1; j <= m; ++j) {
            if (isupper(s[i][j])) {
                ve[s[i][j]].push_back({i, j});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (isupper(s[i][j])) {
                ve[s[i][j]].push_back({i, j});
            }
            if (s[i][j] == '@') {
                sx = i;
                sy = j;
            }
            if (s[i][j] == '=') {
                ex = i;
                ey = j;
            }
        }
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        if (ve[i].empty()) {
            continue;
        }
        trans[ve[i][0].first][ve[i][0].second] = ve[i][1];
        trans[ve[i][1].first][ve[i][1].second] = ve[i][0];
    }

    memset(d, 0x3f, sizeof(d));
    queue<PII> q;

    if (isupper(s[sx][sy])) {
        d[trans[sx][sy].first][trans[sx][sy].second] = 0;
        q.push({trans[sx][sy].first, trans[sx][sy].second});
    } else {
        d[sx][sy] = 0;
        q.push({sx, sy});
    }

    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (1 <= tx && tx <= n && 1 <= ty && ty <= m) {
                if (s[tx][ty] == '#') {
                    continue;
                }

                if (isupper(s[tx][ty])) {
                    if (d[trans[tx][ty].first][trans[tx][ty].second] > d[x][y] + 1) {
                        d[trans[tx][ty].first][trans[tx][ty].second] = d[x][y] + 1;
                        q.push(trans[tx][ty]);
                    }
                    continue;
                }

                if (d[tx][ty] > d[x][y] + 1) {
                    d[tx][ty] = d[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }

    cout << d[ex][ey] << endl;
    return 0;
}