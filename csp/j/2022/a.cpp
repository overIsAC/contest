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
    ifstream cin("pow.in");
    ofstream cout("pow.out");
    LL a, b;
    cin >> a >> b;
    LL ans = 1;
    int overflow = 0;
    while (b) {
        if (b & 1) {
            ans *= a;
            if (overflow || ans > 1e9) {
                cout << -1 << endl;
                return 0;
            }
        }
        b >>= 1;
        a *= a;
        if (a > 1e9) {
            overflow = 1;
        }
    }
    cout << ans << endl;
    return 0;
}