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
const int N = 3 + 1e6;

int n, a[N];

int ok(double z) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += z;
        if ((LL)sum > a[i]) {
            return 0;
        }
        if ((LL)sum < a[i]) {
            return 1;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    double l = 0, r = 2e9;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << r << endl;
    return 0;
}