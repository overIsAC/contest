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

int n, a[N], b[N];

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
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
            }
        }
        LL ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += abs(a[i] - a[i + 1]);
            ans += abs(b[i] - b[i + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}