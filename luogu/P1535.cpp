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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, T;
char s[N][N];
int sx, sy, ex, ey;
int ans;

void dfs(int x, int y, int now) {
    if (abs(x - ex) + abs(y - ey) + now > T) {
        return;
    }
    if (now == T) {
        if (ex == x && ey == y) {
            ++ans;
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (1 <= tx && tx <= n && 1 <= ty && ty <= m) {
            if (s[tx][ty] == '*') {
                continue;
            }
            dfs(tx, ty, now + 1);
        }
    }
}

int main() {
    cin >> n >> m >> T;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    cin >> sx >> sy >> ex >> ey;
    dfs(sx, sy, 0);
    cout << ans << endl;
    return 0;
}