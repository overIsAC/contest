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
const int N = 3 + 500;

int n, q, a[N][N];
int b[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    while (q--) {
        int op, x0, y0, x1, y1;
        cin >> op >> x0 >> y0 >> x1 >> y1;
        int m = x1 - x0 + 1;
        if (op == 1) {
            for (int i = x0; i <= x1; ++i) {
                for (int j = y0; j <= y1; ++j) {
                    int x = i - x0 + 1, y = j - y0 + 1;
                    tie(x, y) = make_pair(y, x1 - x0 + 1 - x + 1);
                    x = x + x0 - 1;
                    y = y + y0 - 1;
                    b[x][y] = a[i][j];
                }
            }
            for (int i = x0; i <= x1; ++i) {
                for (int j = y0; j <= y1; ++j) {
                    a[i][j] = b[i][j];
                }
            }
        } else if (op == 2) {
            for (int i = x0; i <= x1; ++i) {
                for (int j = y0, k = y1; j <= k; ++j, --k) {
                    swap(a[i][j], a[i][k]);
                }
            }
        } else if (op == 3) {
            for (int i = x0, j = x1; i < j; ++i, --j) {
                for (int k = y0; k <= y1; ++k) {
                    swap(a[i][k], a[j][k]);
                }
            }
        } else if (op == 4) {
            for (int i = x0; i <= x1; ++i) {
                for (int j = y0; j <= y1; ++j) {
                    b[i - x0 + 1][j - y0 + 1] = a[i][j];
                }
            }
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j < i; ++j) {
                    swap(b[i][j], b[j][i]);
                }
            }
            for (int i = x0; i <= x1; ++i) {
                for (int j = y0; j <= y1; ++j) {
                    a[i][j] = b[i - x0 + 1][j - y0 + 1];
                }
            }
        } else {
            for (int i = x0; i <= x1; ++i) {
                for (int j = y0; j <= y1; ++j) {
                    b[i - x0 + 1][j - y0 + 1] = a[i][j];
                }
            }
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j < m - i + 1; ++j) {
                    swap(b[i][j], b[m - j + 1][m - i + 1]);
                }
            }
            for (int i = x0; i <= x1; ++i) {
                for (int j = y0; j <= y1; ++j) {
                    a[i][j] = b[i - x0 + 1][j - y0 + 1];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}