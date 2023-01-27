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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        LL ans = a;
        if (a > 0) {
            int t = min(b, c);
            b -= t;
            c -= t;
            ans += t * 2;

            ans += min(max(b, c) + d, a + 1);
        } else {
            ++ans;
        }

        cout << ans << endl;
    }
    return 0;
}