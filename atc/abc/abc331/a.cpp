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

int main() {
    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;
    ++d;
    if (d > D) {
        d = 1;
        ++m;
        if (m > M) {
            m = 1;
            ++y;
        }
    }
    cout << y << ' ' << m << ' ' << d << endl;
    return 0;
}