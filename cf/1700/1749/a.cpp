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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a[22][22] = {};
        int n, m;
        cin >> n >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }
        bool ok = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j])
                    continue;
                int cnt = 0;
                for (int k = 0; k < 4; ++k) {
                    int tx = i, ty = j;
                    while (true) {
                        if (1 <= tx && tx <= n && 1 <= ty && ty <= n) {
                            if (a[tx][ty])
                                ++cnt;
                            tx += dx[k], ty += dy[k];
                        } else {
                            break;
                        }
                    }
                }
                if (cnt == 1) {
                    ok = true;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}