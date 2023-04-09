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
const double PI = acos(-1);

struct Vector {
    int x, y, id;
} a[N];

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a, a + n, [&](const Vector& a, const Vector& b) {
        return atan2<long double>(a.y, a.x) < atan2<long double>(b.y, b.x);
    });
    long double angle = 1e18;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        long double temp = fabs(atan2<long double>(a[(i + 1) % n].y, a[(i + 1) % n].x) - atan2<long double>(a[i].y, a[i].x));
        if (temp > PI) {
            temp = 2 * PI - temp;
        }
        if (angle > temp) {
            angle = temp;
            p = i;
        }
    }
    cout << a[p].id + 1 << ' ' << a[(p + 1) % n].id + 1 << endl;
    return 0;
}