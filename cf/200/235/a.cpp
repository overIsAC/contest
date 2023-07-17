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

LL lcm(LL a, LL b, LL c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    return lcm(a, lcm(b, c));
}

int main() {
    LL n;
    cin >> n;
    LL ans = n;
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            for (int k = 0; k <= 3; ++k) {
                ans = max(ans, lcm(n - i, n - j, n - k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}