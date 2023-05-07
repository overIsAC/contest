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

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        LL cnt[2] = {a[2], a[1]};
        int x[2] = {n - 1, n - 1};
        int y[2] = {a[2], a[1]};
        LL ans = (LL)n* a[1] + (LL)n* a[2];
        for (int i = 3; i <= n; ++i) {
            cnt[i % 2] += a[i];
            --x[i % 2];
            y[i % 2] = min(y[i % 2], a[i]);
            ans = min(ans, cnt[0] + cnt[1] + (LL)x[0] * y[0] + (LL)x[1] * y[1]);
        }
        cout << ans << endl;
    }
    return 0;
}