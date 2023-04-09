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

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL x, y;
        cin >> x >> y;
        if (__gcd(x, y) == 1) {
            cout << 1 << endl;
            cout << x << ' ' << y << endl;
        } else {
            cout << 2 << endl;
            cout << 1 << ' ' << y - 1 << endl;
            cout << x << ' ' << y << endl;
        }
    }
    return 0;
}