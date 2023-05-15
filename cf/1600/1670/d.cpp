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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        auto calc = [&](LL n) {
            LL a = n / 3, b = n / 3, c =n/3;
            if (n % 3) {
                ++a;
                --n;
            }
            if (n % 3) {
                ++b;
            }
            LL ans = a * b * 2;
            ans += a * c * 2;
            ans += b * c * 2;
            return ans;
        };

        LL l = 1, r = 1e9;
        while (l < r) {
            LL mid = (l + r) / 2;
            if (calc(mid) >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}