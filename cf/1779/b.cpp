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
        if (n & 1) {
            if (n == 3) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                int x = n / 2 - 1, y = ((n + 1) >> 1) - 1;
                for (int i = 1; i <= n; ++i) {
                    if (i & 1) {
                        cout << -x << ' ';
                    } else {
                        cout << y << ' ';
                    }
                }
                cout << endl;
            }
        } else {
            cout << "YES" << endl;
            for (int i = 1; i <= n; ++i) {
                if (i & 1) {
                    cout << -1 << ' ';
                } else {
                    cout << 1 << ' ';
                }
            }
            cout << endl;
        }
    }
    return 0;
}