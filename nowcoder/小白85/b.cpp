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
    // for (int i = 1; i <= 100; ++i) {
    //     cout << i << ' ' << i * (i + 1) / 2 % 2 << endl;
    // }
    LL n;
    cin >> n;
    if (n % 2 == 0) {
        cout << 2 * n << endl;
    } else {
        cout << (n / 2 + 1) * 4 - 1 << endl;
    }
    return 0;
}