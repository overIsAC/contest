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
const int N = 3 + 1e5;

char ans[2000][2000];

void dfs(int n, int x, int y) {
    // cout << n << ' ' << x << ' ' << y << endl;
    if (n == 1) {
        ans[x][y + 1] = '/';
        ans[x][y + 2] = '\\';
        ans[x + 1][y] = '/';
        ans[x + 1][y + 1] = '_';
        ans[x + 1][y + 2] = '_';
        ans[x + 1][y + 3] = '\\';
        return;
    }
    dfs(n - 1, x, y + (1 << n - 1));
    dfs(n - 1, x + (1 << n - 1), y);
    dfs(n - 1, x + (1 << n - 1), y + (1 << n));
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= (1 << n); ++i) {
        for (int j = 1; j <= (1 << n + 1); ++j) {
            ans[i][j] = ' ';
        }
    }
    dfs(n, 1, 1);
    for (int i = 1; i <= (1 << n); ++i) {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}