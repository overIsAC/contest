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
    LL a, b;
    cin >> a >> b;
    if (a == 1) {
        cout << 1 << endl;
    } else {
        LL ans = 1;
        while (b--) {
            ans *= a;
            if (ans > 1e9) {
                cout << -1 << endl;
                return 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}