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
    int T;
    cin >> T;
    while (T--) {
        int n, d[123], a[123];
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> d[i];
        }
        bool ok = true;
        a[1] = d[1];
        for (int i = 2; i <= n; ++i) {
            a[i] = d[i] + a[i - 1];
            if (d[i] && d[i] <= a[i - 1]) {
                ok = false;
            }
            db((d[i] <= a[i]));
        }
        if (ok) {
            for (int i = 1; i <= n; ++i) {
                cout << a[i] << ' ';
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}