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

int n;
double a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + n + 1, greater<double>());
    sort(b + 1, b + n + 1, greater<double>());
    double L = 0, R = 1e8;

    auto ok = [](double x) {
        double u = 0, v = 0;
        for (int i = 1, j = 1; i <= n || j <= n;) {
            int flag = 0;
            while (i <= n && u - (i - 1) - (j - 1) < x) {
                u += a[i++];
                flag = 1;
            }
            while (j <= n && v - (i - 1) - (j - 1) < x) {
                v += b[j++];
                flag = 1;
            }
            if (u - (i - 1) - (j - 1) >= x && v - (i - 1) - (j - 1) >= x) {
                return 1;
            }
            if (!flag) {
                return 0;
            }
        }
        return 0;
    };

    while (R - L > 1e-6) {
        double mid = (L + R) / 2;
        if (ok(mid)) {
            L = mid;
        } else {
            R = mid;
        }
    }
    cout << fixed << setprecision(4) << R << endl;
    return 0;
}