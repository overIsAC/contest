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

int a[N], n, b[N];

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
        sort(a + 1, a + n + 1, greater<int>());
        sort(b + 1, b + n + 1, greater<int>());
        LL ans = 1;
        for (int i = 1; i <= n; ++i) {
            int l = 1, r = i;
            while (l < r) {
                int mid = l + r >> 1;
                if (a[i] > b[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (a[i] <= b[r]) {
                ans = 0;
                break;
            }
            ans = ans * (i - r + 1) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}