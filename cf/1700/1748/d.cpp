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
    while (T--) {
        LL a, b, d;
        cin >> a >> b >> d;
        if ((d & -d) > (a & -a) || (d & -d) > (b & -b)) {
            cout << -1 << endl;
            continue;
        }
        int p = 0;
        while (!(d >> p & 1)) {
            ++p;
        }
        LL ans = d;
        for (int i = p; i < 30; ++i) {
            if (!(ans >> i & 1)) {
                ans += d << i - p;
            }
        }
        cout << ans << endl;
    }
    return 0;
}