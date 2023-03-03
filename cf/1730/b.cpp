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
const double eps = 1e-6;

int n;
PII a[N];

signed main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, int> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].second;
        }
        double l = 0, r = 1e9;
        double p = 0;
        auto ok = [&](double v) {
            double L = -2e9, R = 2e9;
            for (int i = 1; i <= n; ++i) {
                L = max(min<double>(a[i].first, a[i].first - (v - a[i].second)), L);
                R = min(max<double>(a[i].first, a[i].first + (v - a[i].second)), R);
            }
            p = L;
            return L <= R;
        };
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (ok(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << fixed << setprecision(10) << p << endl;
    }

    return 0;
}