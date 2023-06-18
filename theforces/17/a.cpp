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
        int n;
        cin >> n;
        vector<LL> a(n);
        LL g = 0;
        for (auto &i : a) {
            cin >> i;
            g = gcd(g, i);
        }
        LL ans = g - 1;
        for (LL i = 2; i < g; ++i) {
            if (gcd(i, g) == 1) {
                ans = i;
                break;
            }
        }
        if (ans == 1) {
            ans = 3;
        }
        cout << ans << endl;
    }
    return 0;
}