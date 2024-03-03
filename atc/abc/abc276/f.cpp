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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int n, m;
int a[N];

LL tr1[N];
LL tr2[N];

void add(LL* tr, int p, int v) {
    for (; p <= 2e5; p += p & -p) {
        tr[p] += v;
    }
}

LL ask(LL* tr, int p) {
    LL ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        LL c = ask(tr1, a[i]);
        ans = (ans + c * a[i] * 2) % mod;
        ans = (ans + (ask(tr2, 2e5) - ask(tr2, a[i]) + mod) * 2 % mod) % mod;
        ans += a[i];
        cout << ans * qpow((LL)i * i % mod, mod - 2) % mod << endl;
        add(tr1, a[i], 1);
        add(tr2, a[i], a[i]);
    }
    return 0;
}