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
    for (int i = 0; i <= n; ++i) {
        char c = '-';
        for (int j = 1; j <= 9; ++j) {
            if (n % j == 0 && i % (n / j) == 0) {
                c = j + '0';
                break;
            }
        }
        cout << c;
    }
    return 0;
}