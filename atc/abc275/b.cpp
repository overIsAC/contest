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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    LL a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a %= mod;
    b %= mod;
    c %= mod;
    d %= mod;
    e %= mod;
    f %= mod;
    a = a * b % mod * c % mod;
    d = d * e % mod * f % mod;
    a = ((a - d) % mod + mod) % mod;
    cout << a << endl;
    return 0;
}