#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, q;
char s[N];
int a[N];

int id[N];
LL c[N];

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int t = 1;
    c[1] = a[1];
    id[1] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '+') {
            c[++t] = a[i + 1];
        } else {
            c[t] = c[t] * a[i + 1] % mod;
        }
        id[i + 1] = t;
    }
    LL sum = 0;
    for (int i = 1; i <= t; ++i) {
        sum = (sum + c[i]) % mod;
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        int p = id[x];
        sum -= c[p];
        c[p] = c[p] * qpow(a[x], mod - 2) % mod;
        a[x] = y;
        c[p] = c[p] * y % mod;
        sum += c[p];
        sum = (sum % mod + mod) % mod;
        cout << sum << endl;
    }
    return 0;
}