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
const int N = 3 + 123;

int n, m;
int d[N][N];
int a[N];

int main() {
    cin >> n >> m;
    for (int j = 1; j <= m; ++j) {
        int q;
        cin >> q;
        for (int i = 1; i <= q; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= q; ++i) {
            for (int k = i + 1; k <= q; ++k) {
                ++d[a[i]][a[k]];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (d[i][j]) {
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}