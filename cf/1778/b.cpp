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

int n, a[N], p[N], m, d;
int q[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> d;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            q[p[i]] = i;
        }
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
        }
        bool flag = true;
        for (int i = 1; i < m; ++i) {
            if (!(q[a[i]] < q[a[i + 1]] && q[a[i + 1]] <= q[a[i]] + d)) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << 0 << endl;
            continue;
        }
        int ans = 1e9;
        for (int i = 1; i < m; ++i) {
            ans = min(ans, q[a[i + 1]] - q[a[i]]);
            if (q[a[i]] + d - q[a[i + 1]] + 1 <= n - q[a[i + 1]] + q[a[i]] - 1) {
                ans = min(ans, q[a[i]] + d - q[a[i + 1]] + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}