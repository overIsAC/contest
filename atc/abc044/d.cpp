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

LL n, s;

int main() {
    cin >> n >> s;
    LL ans = LLONG_MAX;

    auto check = [&](LL n, LL b) {
        LL sum = 0;
        do {
            sum += n % b;
            n /= b;
        } while (n);
        return sum == s;
    };

    for (LL i = sqrt(n) + 1; i >= 2; --i) {
        if (check(n, i)) {
            ans = i;
        }
    }

    if (n >= s) {
        for (LL i = 1; i * i <= n - s; ++i) {
            if ((n - s) % i == 0) {
                if (check(n, i + 1)) ans = min(ans, i + 1);
                if (check(n, (n - s) / i + 1)) ans = min(ans, (n - s) / i + 1);
            }
        }
    }

    if (n == s) {
        ans = min(ans, n + 1);
    }

    if (ans == LLONG_MAX) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}