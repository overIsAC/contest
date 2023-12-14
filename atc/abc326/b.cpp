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
    int n;
    cin >> n;

    auto ok = [&](int n) {
        int a = n / 100, b = n / 10 % 10, c = n % 10;
        return a * b == c;
    };

    while (!ok(n)) {
        ++n;
    }
    cout << n << endl;
    return 0;
}