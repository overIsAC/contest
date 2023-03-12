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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        x = abs(x);
        y = abs(y);
        int ans = min(x, y) * 2;
        int t = abs(x - y);
        if (t) {
            ++ans;
            t -= 1;
            ans += t * 2;
        }
        cout << ans << endl;
    }
    return 0;
}