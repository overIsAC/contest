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
const double eps = 1e-8;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int d;
        cin >> d;
        int delta = d * d - 4 * d;
        if (delta < 0) {
            cout << "N" << endl;
            continue;
        }
        double a = (d + sqrt(delta)) / 2;
        double b = (d - sqrt(delta)) / 2;
        cout << "Y " << fixed << setprecision(10) << a << ' ' << b << endl;
    }
    return 0;
}