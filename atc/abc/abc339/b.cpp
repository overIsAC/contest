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
const int N = 3 + 1e5;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int x = 0, y = 0;
    vector<vector<int>> ans(n, vector<int>(m));
    int dir = 0;
    while (k--) {
        if (ans[x][y] == 0) {
            dir = (dir + 1) % 4;
        } else {
            dir = (dir + 3) % 4;
        }
        ans[x][y] = !ans[x][y];
        if (dir == 1) {
            ++y;
        } else if (dir == 2) {
            ++x;
        } else if (dir == 3) {
            --y;
        } else {
            --x;
        }
        x = (x + n) % n;
        y = (y + m) % m;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ".#"[ans[i][j]];
        }
        cout << endl;
    }
    return 0;
}