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

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q;
        n >>= 1;
        q = q * q;
    }
    return ans;
}

void solve() {
    LL a, b, c, k;
    cin >> a >> b >> c >> k;
    LL down = qpow(10, a - 1);
    LL up = qpow(10, a) - 1;
    for (int i = down; i <= up; ++i) {
        LL L = qpow(10, c - 1);
        LL R = qpow(10, c) - 1;
        L -= i;
        R -= i;
        L = max(L, qpow(10, b - 1));
        R = min(R, qpow(10, b) - 1);
        if (L <= R) {
            if (k <= R - L + 1) {
                cout << i << " + " << L + k - 1 << " = " << i + L + k - 1 << endl;
                return;
            } else {
                k -= R - L + 1;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}