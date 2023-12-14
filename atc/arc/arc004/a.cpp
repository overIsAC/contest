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

int n, x[N], y[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = max(ans, hypot(x[i] - x[j], y[i] - y[j]));
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}