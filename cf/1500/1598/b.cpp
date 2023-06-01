#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
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

int a[N][11];
int n;

void solve() {
    for (int i = 1; i <= 5; ++i) {
        for (int j = i + 1; j <= 5; ++j) {
            int ok = 1, u = 0, v = 0;
            for (int k = 1; k <= n; ++k) {
                if (!a[k][i] && !a[k][j]) {
                    ok = 0;
                    break;
                }
                if (a[k][i]) {
                    ++u;
                }
                if (a[k][j]) {
                    ++v;
                }
            }
            if (ok && u >= n / 2 && v >= n / 2) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 5; ++j) {
                cin >> a[i][j];
            }
        }
        solve();
    }
    return 0;
}