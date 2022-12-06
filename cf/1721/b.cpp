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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        int ans = 1e9;

        if (sx - d > 1 && sy + d < m) {
            ans = min(ans, n + m - 2);
        }
        if (sy - d > 1 && sx + d < n) {
            ans = min(ans, n + m - 2);
        }

        if (ans == 1e9) {
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}