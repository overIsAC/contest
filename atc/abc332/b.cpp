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

int k, g, m;

int main() {
    int a = 0, b = 0;
    cin >> k >> g >> m;
    while (k--) {
        if (b == g) {
            b = 0;
        } else if (!a) {
            a = m;
        } else {
            int t = min(g - b, a);
            a -= t;
            b += t;
        }
    }
    cout << b << ' ' << a << endl;
    return 0;
}