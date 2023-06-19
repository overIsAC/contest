#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;
const double PI = acos(-1);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (!x1 && !x2) {
            cout << abs(y1 - y2) << endl;
            continue;
        }
        if (!y1 && !y2) {
            cout << abs(x1 - x2) << endl;
            continue;
        }
        y1 = abs(y1);
        x2 = abs(x2);
        x1 = abs(x1);
        y2 = abs(y2);

        LL l = 0, r = abs(x1 + y1);

        auto calc = [&](LL d) {
            long double ans = d + ((x1 + y1) - d) * 2 * PI / 4 + abs((x2 + y2) - ((x1 + y1) - d));
            return ans;
        };

        while (r - l > 5) {
            LL m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
            if (calc(m1) <= calc(m2)) {
                r = m2;
            } else {
                l = m1;
            }
        }
        long double ans = calc(r);
        for (int i = l; i < r; ++i) {
            ans = min(ans, calc(i));
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}