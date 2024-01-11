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

const int N = 3 + 111;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n;
string s[N][N];
int dir = 0;

int main() {
    cin >> n;
    int x = 1, y = 1;
    for (int i = 1; i <= n * n - 1; ++i) {
        s[x][y] = to_string(i);
        // cout << x << ' ' << y << endl;

        int tx = dx[dir] + x, ty = dy[dir] + y;
        if (1 <= tx && tx <= n && 1 <= ty && ty <= n && s[tx][ty].empty()) {
        } else {
            dir = (dir + 1) % 4;
        }
        x += dx[dir];
        y += dy[dir];
    }
    s[x][y] = 'T';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << s[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}