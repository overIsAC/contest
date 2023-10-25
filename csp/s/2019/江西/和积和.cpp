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
const int N = 3 + 5e5;

int n, a[N], b[N];

LL calc(int *a, int *b) {
    LL ans = 0, t = 0;
    for (int i = 1; i <= n; ++i) {
        t += (LL)i * a[i];
        t %= mod;
        ans += (LL)(n - i + 1) * b[i] % mod * t;
        ans %= mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    LL ans = 0;
    ans += calc(a, b);
    ans += calc(b, a);
    for (int i = 1; i <= n; ++i) {
        ans -= (LL)a[i] * b[i] % mod * i % mod * (n - i + 1);
        ans %= mod;
    }
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;
    return 0;
}