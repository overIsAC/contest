#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, c, d, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> c >> d;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int t = unique(a + 1, a + n + 1) - a - 1;
        LL ans = LLONG_MAX;
        for (int i = 1; i <= t; ++i) {
            ans = min(ans, (LL)(a[i] - i) * d + (LL)(t - i) * c);
        }
        ans += (LL)(n - t) * c;
        ans = min(ans, (LL)n * c + d);
        cout << ans << endl;
    }
    return 0;
}