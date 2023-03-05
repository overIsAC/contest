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

int n, k, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        bool ok = false;

        auto out = [](int n, int i, int j, int x, int y) {
            int cur = 1, cnt = 0;
            for (int k = 2; k <= n; ++k) {
                if (i) {
                    if (cnt == x) {
                        cur = k;
                        --i;
                        cnt = 0;
                    }
                } else {
                    if (cnt == y) {
                        cur = k;
                        cnt = 0;
                    }
                }
                cout << cur << ' ';
                ++cnt;
            }
            cout << endl;
        };

        int m = n;
        --n;

        if (!x && !y) {
        } else if (!y) {
            if (n % x == 0) {
                out(m, n / x, 0, x, y);
                ok = true;
            }
        } else if (!x) {
            if (n % y == 0) {
                out(m, 0, n / y, x, y);
                ok = true;
            }
        } else {
        }

        if (!ok) {
            cout << -1 << endl;
        }
    }
    return 0;
}