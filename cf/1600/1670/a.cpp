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

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int sign = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] < 0) {
                ++sign;
                a[i] = -a[i];
            }
        }
        for (int i = 1; i <= n && sign; ++i) {
            --sign;
            a[i] = -a[i];
        }
        bool ok = true;
        for (int i = 2; i <= n; ++i) {
            if (a[i] < a[i - 1]) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}