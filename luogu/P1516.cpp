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

LL a, b;
LL x, y, m, n, L;

LL exgcd(LL x, LL y, LL& a, LL& b) {
    if (!y) {
        a = 1;
        b = 0;
        return x;
    }
    LL g = exgcd(y, x % y, a, b), t = b;
    b = a - x / y * b;
    a = t;
    return g;
}

int main() {
    cin >> x >> y >> m >> n >> L;
    if (n < m) {
        swap(x, y);
        swap(n, m);
    }
    LL g = exgcd(n - m, L, a, b);
    if ((x - y) % g) {
        cout << "Impossible" << endl;
        return 0;
    }
    LL mod = L / g;
    cout << (a % mod * ((x - y) / g) % mod + mod) % mod << endl;

    return 0;
}