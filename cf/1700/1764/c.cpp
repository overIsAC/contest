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

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        LL ans = 0;
        for (int i = n; i; --i) {
            if (a[i] != a[i - 1]) {
                ans = max(ans, (LL)(i - 1) * (n - i + 1));
            }
        }
        if (a[n] == a[1]) {
            ans = max<LL>(ans, n / 2);
        }
        cout << ans << endl;
    }
    return 0;
}