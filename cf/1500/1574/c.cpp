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
const int N = 3 + 2e5;

int n, q;
LL a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    LL sum = accumulate(a + 1, a + n + 1, 0LL);
    cin >> q;
    while (q--) {
        LL x, y;
        cin >> x >> y;
        auto calc = [&](int p) -> LL {
            if (1 <= p && p <= n) {
                return max<LL>(0, x - a[p]) + max<LL>(0, y - (sum - a[p]));
            }
            return LLONG_MAX;
        };
        int p = lower_bound(a + 1, a + n + 1, x) - a;
        cout << min(calc(p), calc(p - 1)) << endl;
    }
    return 0;
}