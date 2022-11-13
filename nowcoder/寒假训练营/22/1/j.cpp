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

int n, a[N], m, b[N], t;
LL prea[N], preb[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> t;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; ++i) {
            cin >> b[i];
        }
        sort(a + 1, a + n + 1, greater<int>());
        sort(b + 1, b + m + 1, greater<int>());
        for (int i = 1; i <= n; ++i) {
            prea[i] = prea[i - 1] + a[i];
        }
        for (int i = 1; i <= m; ++i) {
            preb[i] = preb[i - 1] + b[i];
        }
        LL ans = -1;
        for (int i = 0; i <= t && i <= n; ++i) {
            int j = t - i;
            if (j < 0 || j > i  || j > m) {
                continue;
            }
            ans = max(ans, prea[i] + preb[j]);
        }
        cout << ans << endl;
    }

    return 0;
}