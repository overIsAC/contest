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

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL n, d, k;
        cin >> n >> d >> k;
        LL g = n / __gcd(n, d) * d;
        if (k % (g / d)) {
            LL ans = k / (g / d) + (k % (g / d) - 1) * d;
            ans %= n;
            ans = (ans + n) % n;
            cout << ans << endl;
        } else {
            cout << (k / (g / d) - 1 + (g / d - 1) * d) % n << endl;
        }
    }
    return 0;
}