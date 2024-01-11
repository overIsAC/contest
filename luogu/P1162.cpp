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
const int N = 3 + 333;
const double PI = acos(-1);
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, a[N][N];

void dfs(int x, int y) {
    if (a[x][y]) {
        return;
    }
    if (!(1 <= x && x <= n && 1 <= y && y <= n)) {
        return;
    }
    a[x][y] = 3;
    for (int i = 0; i < 4; ++i) {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, 1);
        dfs(i, n);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(1, i);
        dfs(n, i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == 0) {
                cout << 2 << ' ';
            } else if (a[i][j] == 3) {
                cout << 0 << ' ';
            } else {
                cout << a[i][j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}