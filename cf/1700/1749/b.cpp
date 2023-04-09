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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], b[N];
LL pre[N], suf[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        LL ans = 1e18, temp = 0;

        for (int i = 1; i <= n; ++i) {
            temp += a[i];
            pre[i] = pre[i - 1] + b[i];
        }
        suf[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            suf[i] = suf[i + 1] + b[i];
        }
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, pre[i - 1] + suf[i + 1] + temp);
        }

        cout << ans << endl;
    }
    return 0;
}