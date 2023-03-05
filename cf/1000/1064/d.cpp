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
const int N = 3 + 2e3;

int n, m, r, c, x, y;
priority_queue<pair<int, PII>> q;
int d[N][N];
char s[N][N];
bool vis[N][N];
bool vis2[N][N];

int main() {
    cin >> n >> m >> r >> c >> x >> y;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    memset(d, -1, sizeof(d));
    d[r][c] = x;
    q.push({x, {r, c}});
    while (true) {
        priority_queue<pair<int, PII>> q2;
        while (q.size()) {
            auto xx = q.top().second.first, yy = q.top().second.second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int tx = xx + dx[i], ty = yy + dy[i];
                if (1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] == '.') {
                    if (i == 2) {
                        q2.push({d[xx][yy], {tx, ty}});
                        continue;
                    }
                    int w = (i <= 1 ? 0 : 1);
                    if (d[tx][ty] < d[xx][yy] - w) {
                        d[tx][ty] = d[xx][yy] - w;
                        q.push({d[tx][ty], {tx, ty}});
                    }
                }
            }
        }
        if (q2.empty() || y <= 0) {
            break;
        }
        --y;
        while (q2.size()) {
            auto u = q2.top();
            q2.pop();
            if (u.first > d[u.second.first][u.second.second]) {
                d[u.second.first][u.second.second] = u.first;
                q.push(u);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (d[i][j] >= 0) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}