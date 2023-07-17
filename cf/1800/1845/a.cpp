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
    int T;
    cin >> T;
    while (T--) {
        int n, k, x;
        cin >> n >> k >> x;
        if (x != 1) {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 1; i <= n; ++i) {
                cout << 1 << ' ';
            }
            cout << endl;
            continue;
        }
        if (n % 2 == 0 && k >= 2) {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            for (int i = 1; i <= n / 2; ++i) {
                cout << 2 << ' ';
            }
            cout << endl;
            continue;
        }
        if (k >= 3 && n >= 3) {
            cout << "YES" << endl;
            cout << n / 2 << endl;
            cout << 3 << ' ';
            n -= 3;
            while (n > 0) {
                n -= 2;
                cout << 2 << ' ';
            }
            cout << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}