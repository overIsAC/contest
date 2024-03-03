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
    LL n;
    cin >> n;
    LL ans = LLONG_MAX;
    for (LL i = 0; i <= 1e6; ++i) {
        LL l = 0, r = 1e6;

        auto calc = [&](LL j) {
            return i * i * i + i * i * j + i * j * j + j * j * j;
        };

        while (l < r) {
            LL mid = l + r >> 1;
            if (calc(mid) >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = min(ans, calc(r));
    }
    cout << ans << endl;
    return 0;
}