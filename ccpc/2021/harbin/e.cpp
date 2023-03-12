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

void solve() {
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if ((1 << (i - 1)) < a[i]) {
            cout << -1 << endl;
            return;
        }
        if ((1 << (i - 1)) > a[i]) {
            flag = false;
        }
        if (i >= 31) {
            break;
        }
    }
    if (flag) {
        cout << -1 << endl;
        return;
    }
    LL g = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < (1LL << (i - 1))) {
            g = __gcd(g, (1LL << (i - 1)) - a[i]);
        }
        if (1LL << (i - 1) >= 1e18) {
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (g <= a[i]) {
            cout << -1 << endl;
            return;
        }
        auto qpow = [&](LL q, LL n) {
            LL ans = 1;
            while (n) {
                if (n & 1) {
                    ans = ans * q % g;
                }
                q = q * q % g;
                n >>= 1;
            }
            return ans % g;
        };
        if (qpow(2, i - 1) != a[i] % g) {
            cout << -1 << endl;
            return;
        }
    }
    cout << g << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}