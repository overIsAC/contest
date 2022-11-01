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
const int N = 3 + 1e6;

int n, m;
vector<LL> a[N];
vector<int> d[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    a[0].resize(m + 1, -2333);
    for (int i = 1; i <= n; ++i) {
        a[i].resize(m + 1, -2333);
        d[i].resize(m + 1, -2333);
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == a[i][j - 1]) {
                d[i][j] = d[i][j - 1] + 1;
            } else {
                d[i][j] = 1;
            }
        }
    }
    int x, y;
    cin >> x >> y;
    for (int j = 1; j <= m; ++j) {
        int c = 0;
        for (int i = 1; i <= n; ++i) {
            if (d[i][j] >= y) {
                if (a[i][j] == a[i - 1][j]) {
                    ++c;
                } else {
                    c = 1;
                }
            } else {
                c = 0;
            }
            if (c >= x) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    for (int j = 1; j <= m; ++j) {
        int c = 0;
        for (int i = 1; i <= n; ++i) {
            if (d[i][j] >= x) {
                if (a[i][j] == a[i - 1][j]) {
                    ++c;
                } else {
                    c = 1;
                }
            } else {
                c = 0;
            }
            if (c >= y) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}