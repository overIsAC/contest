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

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL x, y;
        cin >> x >> y;
        if (x == y) {
            cout << x << endl;
            continue;
        }
        if (x > y) {
            LL ans = 1e9;
            ans = x * ans + y;
            cout << ans << endl;
            continue;
        }
        cout << y - y % x / 2 << endl;
    }
    return 0;
}