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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const double PI = acos(-1);
const int N = 3 + 1e5;

int n;
double R, theta, r[N];

int main() {
    cin >> n >> R >> theta;
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    theta = min(2 * PI - theta, theta);
    double ans = min(2 * R, theta * R);
    sort(r + 1, r + n + 1);

    /*
    theta / 2pi * pi r*2
    */

    for (int i = 1; i <= n; ++i) {
        double c = theta * r[i];
        ans = min(ans, 2 * R - 2 * r[i] + c);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}