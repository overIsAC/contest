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
const int N = 3 + 2e5;

int n, m, a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL L = *max_element(a + 1, a + n + 1);
    LL R = accumulate(a + 1, a + n + 1, 0LL) + n;

    auto ok = [&](LL z) {
        LL now = a[1], cnt = 1;
        for (int i = 2; i <= n; ++i) {
            if (now + 1 + a[i] <= z) {
                now += 1 + a[i];
            } else {
                ++cnt;
                now = a[i];
            }
        }
        return cnt <= m;
    };

    while (L < R) {
        LL mid = L + R >> 1;
        if (ok(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << R << endl;
    return 0;
}