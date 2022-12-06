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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], x;
LL pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + a[i];
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            int L = 0, R = 1e9;
            auto ok = [&](int v) { return pre[i] + (LL)(v - 1) * i <= x; };
            while (L < R) {
                int mid = L + R + 1 >> 1;
                if (ok(mid)) {
                    L = mid;
                } else {
                    R = mid - 1;
                }
            }
            ans += R;
        }
        cout << ans << endl;
    }
    return 0;
}