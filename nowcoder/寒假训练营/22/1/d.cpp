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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e5;

int n;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        int a = 1, b = n;
        for (int i = 2; i <= n && (LL)a * i <= n; ++i) {
            if (isPrime(i)) {
                a *= i;
            }
        }
        while (!isPrime(b)) {
            --b;
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}