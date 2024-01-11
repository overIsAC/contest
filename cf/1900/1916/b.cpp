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
    LL x, y;
    cin >> x >> y;
    LL g = gcd(x, y), l = lcm(x, y);
    if (l > y) {
        cout << l << endl;
        return;
    }
    for (int i = 2; i * i <= y; ++i) {
        if (y % i == 0) {
            cout << i * l << endl;
            return;
        }
    }
    cout << y * l << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}