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
    int y;
    cin >> y;
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}