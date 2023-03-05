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

const int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[] = {-1, 1, 2, -2, 2, -2, 1, -1};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        int x = 1, y = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                bool ok = true;
                for (int k = 0; k < 8; ++k) {
                    int tx = dx[k] + i, ty = dy[k] + j;
                    if (1 <= tx && tx <= n && 1 <= ty && ty <= m) {
                        ok = false;
                    }
                }
                if (ok) x = i, y = j;
            }
        }
        cout << x << ' ' << y << endl;
    }
    return 0;
}