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
        LL ans = 1, mn = 1e18;
        int n;
        cin >> n;
        int zero = 0;
        while (n--) {
            LL a;
            cin >> a;
            if (!a) {
                ++zero;
                continue;
            }
            ans *= a;
            mn = min(mn, a);
        }
        if (zero == 0) {
            ans = ans / mn * (mn + 1);
        } else if (zero == 1) {
        } else {
            ans = 0;
        }
        cout << ans << endl;
    }

    return 0;
}