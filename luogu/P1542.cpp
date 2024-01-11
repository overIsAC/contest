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

int n;
int x[N], y[N], s[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> s[i];
    }
    long double l = 0, r = 1e7;

    auto ok = [&](long double z) {
        long double now = 0;
        for (int i = 1; i <= n; ++i) {
            if (now + s[i] / z > y[i]) {
                return 0;
            }
            now = max(now + s[i] / z, (long double)x[i]);
        }
        return 1;
    };

    while (r - l > 1e-4) {
        long double mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(2) << r << endl;
    return 0;
}