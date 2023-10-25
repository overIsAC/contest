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
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    auto dist = [&](int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };

    auto ok = [&](double r) {
        if (dist(ax, ay, 0, 0) <= r * r) {
            if (dist(ax, ay, px, py) <= r * r) {
                return 1;
            }
            if (dist(bx, by, ax, ay) <= (r + r) * (r + r)) {
                if (dist(bx, by, px, py) <= r * r) {
                    return 1;
                }
            }
        }
        if (dist(bx, by, 0, 0) <= r * r) {
            if (dist(bx, by, px, py) <= r * r) {
                return 1;
            }
            if (dist(bx, by, ax, ay) <= (r + r) * (r + r)) {
                if (dist(ax, ay, px, py) <= r * r) {
                    return 1;
                }
            }
        }
        return 0;
    };

    double l = 0, r = 1e9;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(10) << r << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}