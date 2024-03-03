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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e6;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
string s[N];
int sx, sy;

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && s[x][y] == '.';
};

bool dfs(int x, int y, int d) {
    for (int j = 0; j < 4; ++j) {
        int tx = x + dx[j];
        int ty = y + dy[j];
        if (tx == sx && ty == sy && d != 1) {
            return true;
        }
        if (tx == sx && ty == sy) {
            continue;
        }
        if (!check(tx, ty)) {
            continue;
        }
        s[tx][ty] = '#';
        if (dfs(tx, ty, d + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        if (!check(tx, ty)) {
            continue;
        }
        s[tx][ty] = '#';
        if (dfs(tx, ty, 1)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}