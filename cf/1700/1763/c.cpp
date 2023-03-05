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
const int N = 3 + 2e5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        a[3] = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int v = *max_element(a + 1, a + n + 1);
        bool ok = false;
        LL sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            if (a[i] == v) {
                if (i > 2) {
                    ok = true;
                }
                if (n - i >= 2) {
                    ok = true;
                }
            }
        }
        if (n == 1) {
            cout << a[1] << endl;
        } else if (n == 2) {
            cout << max(sum, abs(a[1] - a[2]) * 2LL) << endl;
        } else if (ok) {
            cout << (LL)v * n << endl;
        } else {
            sum = max(sum, 3LL * a[1]);
            sum = max(sum, 3LL * a[3]);
            sum = max(sum, 2LL * abs(a[1] - a[2]) + a[3]);
            sum = max(sum, 2LL * abs(a[2] - a[3]) + a[1]);
            sum = max(sum, 3LL * abs(a[1] - a[2]));
            sum = max(sum, 3LL * abs(a[2] - a[3]));
            sum = max(sum, 3LL * abs(a[1] - a[3]));
            cout << sum << endl;
        }
    }
    return 0;
}