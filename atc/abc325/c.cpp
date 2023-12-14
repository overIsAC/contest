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
const int N = 3 + 1111;

int n, m;
char s[N][N];

void dfs(int x, int y) {
    if (s[x][y] == '#') {
        s[x][y] = '.';
        for (int tx = x - 1; tx <= x + 1; ++tx) {
            for (int ty = y - 1; ty <= y + 1; ++ty) {
                dfs(tx, ty);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '#') {
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}