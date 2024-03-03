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

void solve() {
    LL n, x, k;
    cin >> n >> x >> k;
    LL ans = 0;

    auto get = [&](LL x, LL k) -> pair<LL, LL> {
        LL l = x, r = x;
        if (k == 0) {
            return {l, r};
        }
        while (k) {
            l = l * 2;
            r = r * 2 + 1;
            k -= 1;
            if (l > n) {
                return {l, r};
            }
        }
        r = min(n, r);
        return {l, r};
    };

    while (x && k >= 0) {
        auto v = get(x, k);
        if (v.first > n) {
            continue;
        }
        ans += v.second - v.first + 1;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}