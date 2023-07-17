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
    LL n, m;
    int q;
    cin >> n >> m >> q;
    LL g = gcd(n, m);

    auto get = [&](LL x, LL y) {
        --y;
        if (x == 1) {
            return y / (n / g);
        } else {
            return y / (m / g);
        }
    };


    while (q--) {
        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        LL c1 = get(x1, y1), c2 = get(x2, y2);
        if (c1 == c2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}