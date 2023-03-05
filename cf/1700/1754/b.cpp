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
        int n;
        cin >> n;
        if (n % 2) {
            cout << n << ' ';
        }
        for (int i = n / 2; i >= 1; --i) {
            cout << i << ' ';
            if (i + n / 2 <= n) {
                cout << i + n / 2 << ' ';
            }
        }

        cout << endl;
    }
    return 0;
}