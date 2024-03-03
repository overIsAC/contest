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
    int n, k;
    int a[222];
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    auto check = [&](int x) {
        do {
            int v = x % 10;
            for (int i = 1; i <= k; ++i) {
                if (v == a[i]) return false;
            }
            x /= 10;
        } while (x);
        return true;
    };

    while (!check(n)) {
        ++n;
    }
    cout << n << endl;

    return 0;
}