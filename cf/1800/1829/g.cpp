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
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        int p = 1;
        while ((LL)(p + 1) * (p + 2) / 2 < n) {
            ++p;
        }
        int l = n, r = n;
        LL ans = 0;
        int cnt = 0;
        auto calc = [&](LL n) {
            return n * (n + 1) * (2 * n + 1) / 6;
        };
        while (p >= 0) {
            for (int i = l; i <= r; ++i) {
                ans += (LL)i * i;
                ++cnt;
            }
            // ans += calc(r) - calc(l -1);
            l -= p + 1;
            r -= p;
            int R = (LL)p * (p + 1) / 2;
            --p;
            int L = (LL)p * (p + 1) / 2 + 1;
            l = max(l, L);
            r = min(r, R);
        }
        db(cnt);
        cout << ans << endl;
    }
    return 0;
}