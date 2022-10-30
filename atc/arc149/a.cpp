#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
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
    auto fun = [&](LL n) {
        cout << n << endl;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                cout << i << ' ';
            }
        }
        cout << endl;
    };

    for (LL i = 11; i <= 1111111; i = i * 10 + 1) {
        fun(i);
    }
    return 0;
}