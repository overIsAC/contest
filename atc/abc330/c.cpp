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

LL d;

int main() {
    cin >> d;
    LL ans = d;
    for (LL x = 0; x * x <= d; ++x) {
        LL y = sqrtl(d - x * x);
        ans = min(ans, d - (x * x + y * y));
        ++y;
        ans = min(ans, abs(d - (x * x + y * y)));
    }
    cout << ans << endl;
    return 0;
}