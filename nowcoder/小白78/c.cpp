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

int main() {
    int k, a, b;
    cin >> k >> a >> b;
    LL l = 1, r = 1e18;

    auto calc = [&](LL v) {
        LL ans = 0;
        if (a == b) {
            return v / a;
        } else {
            for (int i = 0; i <= k; ++i) {
                if ((LL)i * a > v) {
                    break;
                }
                ++ans;
                ans += (v - (LL)i * a) / b;
            }
            --ans;
        }
        return ans;
    };

    while (l < r) {
        LL mid = l + r >> 1;
        if (calc(mid) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}