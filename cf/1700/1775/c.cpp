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
        LL n, x;
        cin >> n >> x;
        if (x > n) {
            cout << -1 << endl;
            continue;
        }
        if (n == x) {
            cout << n << endl;
            continue;
        }
        bool ok = false;
        for (int i = 62; i >= 0; --i) {
            int u = n >> i & 1;
            int v = x >> i & 1;
            if (v > u) {
                ok = false;
                break;
            }
            if (u == v) {
                continue;
            }
            ok = true;
            LL ans = n;
            int j = i + 1;
            while (ans >> j & 1) {
                ++j;
            }
            ans ^= 1LL << j;
            --j;
            while (j >= 0) {
                if (x >> j & 1) {
                    ok = false;
                }
                ans &= ~(1LL << j);
                --j;
            }
            if (!ok) {
                break;
            }
            cout << ans << endl;
            break;
        }
        if (!ok) {
            cout << -1 << endl;
        }
    }
    return 0;
}