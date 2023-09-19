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

mt19937 rnd(time(NULL));

void solve() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    if (a == x && a == 10) {
        cout << "Sorry,NoBruteForce" << endl;
        return;
    }
    if (b == y && b == 10) {
        cout << "Sorry,NoBruteForce" << endl;
        return;
    }
    if (c == z && c == 10) {
        cout << "Sorry,NoBruteForce" << endl;
        return;
    }

    double ans = 0;

    vector<int> u = {a, b, c}, v = {x, y, z};

    function<void(int, double, int)> f = [&](int cnt, double p, int over) {
        if (over) {
            ans += p * cnt;
            return;
        }
        if (p <= 1e-10) {
            return;
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                f(cnt + 1, p * u[i] * v[j] / 100, i != j);
            }
        }
    };

    f(0, 1, 0);

    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}