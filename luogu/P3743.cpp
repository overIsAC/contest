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

int n, p, a[N], b[N];

int ok(double z) {
    double sum = z * p;
    for (int i = 1; i <= n; ++i) {
        if (z * a[i] > b[i]) {
            sum -= z * a[i] - b[i];
        }
    }
    return sum >= 0;
}

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    double l = 0, r = 1e12;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (ok(2e12)) {
        r = -1;
    }
    cout << fixed << setprecision(10) << r << endl;
    return 0;
}


