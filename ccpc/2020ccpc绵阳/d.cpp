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
    int T, Case = 0;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        auto ok = [&](LL v) {
            LL c = v;
            for (int i = 1; i <= n; ++i) {
                LL o = a[i] - v;
                if (o >= 0) continue;
                c += o;
                if (c < 0) {
                    return false;
                }
            }
            return true;
        };
        LL l = 0, r = 1e10;
        while (l < r) {
            LL mid = l + r + 1 >> 1;
            if (ok(mid))
                l = mid;
            else
                r = mid - 1;
        }
        cout << "Case #" << ++Case << ": " << r + 1 << endl;
    }
    return 0;
}