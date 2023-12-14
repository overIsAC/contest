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
    LL n;
    cin >> n;
    for (LL i = 1; i <= n; i *= 2) {
        for (LL j = i; j <= n; j *= 3) {
            if (j == n) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}