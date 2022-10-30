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

int main() {
    int T;
    cin >> T;

    auto sqr = [](LL n) {
        LL l = 1, r = 1e9;
        while (l < r) {
            LL mid = l + r + 1 >> 1;
            if (mid * mid <= n) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return r;
    };

    while (T--) {
        LL l, r;
        cin >> l >> r;
        auto calc = [&](LL n) {
            LL ans = (sqr(n) - 1) * 3;
            LL v = sqr(n);
            if (v * v <= n) ++ans;
            if (v * v + v <= n) ++ans;
            if (v * v + v + v <= n) ++ans;
            return ans;
        };
        cout << calc(r) - calc(l - 1) << endl;
    }

    return 0;
}