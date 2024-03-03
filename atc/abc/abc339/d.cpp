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
const int N = 3 + 60;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int n;
char s[N][N];
int d[N][N][N][N]; //60^4
queue<tuple<int, int, int, int>> q;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int x1 = -1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] != 'P') {
                continue;
            }
            if (x1 == -1) {
                x1 = i;
                y1 = j;
            } else {
                x2 = i;
                y2 = j;
            }
        }
    }

    memset(d, 0x3f, sizeof(d));
    d[x1][y1][x2][y2] = 0;
    q.push({x1, y1, x2, y2});
    while (q.size()) {
        auto [x1, y1, x2, y2] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int _x1 = x1 + dx[i], _y1 = y1 + dy[i];
            int _x2 = x2 + dx[i], _y2 = y2 + dy[i];
            if (!(0 <= _x1 && _x1 < n && 0 <= _y1 && _y1 < n && s[_x1][_y1] != '#')) {
                _x1 = x1;
                _y1 = y1;
            }
            if (!(0 <= _x2 && _x2 < n && 0 <= _y2 && _y2 < n && s[_x2][_y2] != '#')) {
                _x2 = x2;
                _y2 = y2;
            }
            if (d[_x1][_y1][_x2][_y2] > d[x1][y1][x2][y2] + 1) {
                q.push({_x1, _y1, _x2, _y2});
                d[_x1][_y1][_x2][_y2] = d[x1][y1][x2][y2] + 1;
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = min(ans, d[i][j][i][j]);
        }
    }
    if (ans >= 1e9) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}