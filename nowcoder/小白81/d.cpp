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

void solve() {
    int m, a;
    cin >> m >> a;
    int u = 0, v = 0, x = 0, y = 0;
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0 && i + a <= m) {
            ++v;
            x += i;
            y += a;
        }
    }
    for (int i = a + a; i + a <= m; i += a) {
        x += i;
        y += a;
        ++u;
    }
    if (x > y) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}