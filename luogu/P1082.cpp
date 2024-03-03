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

LL x, y, a, b;

LL exgcd(LL a, LL b, LL& x, LL& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    LL g = exgcd(b, a % b, x, y), t = y;
    y = x - a / b * y;
    x = t;
    return g;
}

int main() {
    cin >> a >> b;
    LL g = exgcd(a, b, x, y);
    db(g);
    db(x);
    db(y);
    LL mod = b / g;
    db(mod);
    cout << (x % mod + mod) % mod << endl;
    return 0;
}