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
    LL a, b;
    cin >> a >> b;
    LL l = 0, r = 1e18 / b;

    auto calc = [&](LL t) {
        return t * b + a / sqrtl(t + 1);
    };

    while (l < r) {
        LL mid = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if (calc(mid) > calc(mid2)) {
            l = mid + 1;
        } else {
            r = mid2 - 1;
        }
    }
    long double ans = calc(l);
    for (LL i = l + 1; i <= r; ++i) {
        ans = min(ans, calc(i));
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}