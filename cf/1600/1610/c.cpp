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
const int N = 3 + 2e5;

int n, a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }
        int l = 1, r = n;

        auto ok = [&](int v) {
            int p = 1;
            for (int i = 1; i <= n; ++i) {
                if (a[i] >= v - p && b[i] >= p - 1) ++p;
                if (p > v) return true;
            }
            return false;
        };

        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (ok(mid))
                l = mid;
            else
                r = mid - 1;
        }
        db(ok(2)) ;
        cout << r << endl;
    }
    return 0;
}