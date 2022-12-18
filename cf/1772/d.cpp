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

int n;
LL a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        n = unique(a + 1, a + n + 1) - a - 1;
        if (n == 1) {
            cout << a[1] << endl;
            continue;
        }
        int L = 0, R = 1e9;
        for (int i = 2; i <= n; ++i) {
            int l = 0, r = 0;
            if (a[i - 1] < a[i]) {
                l = 0;
                r = (a[i - 1] + a[i]) / 2;
            } else {
                l = (a[i - 1] + a[i] + 1) / 2;
                r = 1e9;
            }
            L = max(l, L);
            R = min(r, R);
        }
        if (L <= R) {
            cout << L << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}