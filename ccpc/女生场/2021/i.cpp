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

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 111;

int n, m;
char s[N][N];
int q;
string str;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*') {
                x = i;
                y = j;
            }
        }
    }
    int v = 0, dir = 0;
    cin >> q >> str;
    for (auto &i : str) {
        if (i == 'L') {
            dir = (dir - 1 + 8) % 8;
        } else if (i == 'R') {
            dir = (dir + 1) % 8;
        } else if (i == 'U') {
            ++v;
        } else {
            --v;
            if (v < 0) {
                v = 0;
            }
        }

        auto check = [&](int x, int y) {
            return 1 <= x && x <= n && 1 <= y && y <= m && s[x][y] != '#';
        };

        int crash = 0;
        for (int i = v; i >= 1; --i) {
            int tx = dx[dir] + x, ty = dy[dir] + y;
            if (!check(tx, ty)) {
                v = 0;
                crash = 1;
                break;
            }
            if (dx[dir] && dy[dir]) {
                if (!check(x, y + dy[dir]) && !check(x + dx[dir], y)) {
                    v = 0;
                    crash = 1;
                    break;
                }
            }
            x = tx;
            y = ty;
        }
        if (crash) {
            cout << "Crash! ";
        }
        cout << x << ' ' << y << endl;
    }
    return 0;
}

/*

....
##..
..#.
.*..
....

*/