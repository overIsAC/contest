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

int n, r, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int t = 0;
        cin >> n >> r;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        sort(a + 1, a + n + 1);
        n = unique(a + 1, a + n + 1) - a - 1;
        for (int i = n; i >= 1; --i) {
            if (t < a[i]) {
                ++ans;
                t += r;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}