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

bool isPrime(LL n) {
    if (n == 1)
        return false;
    for (LL i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        a -= c - 1;
        b -= c - 1;
        int m = max(a, b) - 1;
        LL p = 1;
        while (m-- > 0) {
            p *= 10;
        }
        while (!isPrime(p))
            ++p;
        if (a < b) {
            db("");
            cout << 1;
            for (int i = 1; i < a; ++i) {
                cout << 0;
            }
            for (int i = 1; i <= c - 1; ++i) {
                cout << 0;
            }
            cout << ' ';
            cout << p;
            for (int i = 1; i <= c - 1; ++i) {
                cout << 0;
            }
        } else {
            db("");
            cout << p;
            for (int i = 1; i <= c - 1; ++i) {
                cout << 0;
            }
            cout << ' ';
            cout << 1;
            for (int i = 1; i < b; ++i) {
                cout << 0;
            }
            for (int i = 1; i <= c - 1; ++i) {
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}