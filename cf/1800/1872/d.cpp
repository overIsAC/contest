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

void solve() {
    LL n, x, y;
    cin >> n >> x >> y;
    LL u = n / x - n / (x * y / __gcd(x, y)), v = n / y - n / (x * y / __gcd(x, y));
    LL ans = u * (n + n - u + 1) / 2;
    ans -= v * (1 + v) / 2;
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}