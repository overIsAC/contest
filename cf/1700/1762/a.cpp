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

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 2 == 0) {
            cout << 0 << endl;
        } else {
            int mn = 1e9;
            for (int i = 1; i <= n; ++i) {
                int x = a[i];
                int c = 0;
                while (a[i]) {
                    a[i] /= 2;
                    ++c;
                    if (x - a[i] & 1) {
                        mn = min(c, mn);
                    }
                }
            }
            cout << mn << endl;
        }
    }
    return 0;
}