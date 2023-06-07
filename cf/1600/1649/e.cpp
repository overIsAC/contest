#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int n, m, a[N], b[N];
LL fac[N];
int tr[N];

void add(int *tr, int p, int v) {
    for (; p < N; p += p & -p) {
        tr[p] += v;
    }
}

int ask(int *tr, int p) {
    int ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    *fac = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    for (int i = 1; i <= n; ++i) {
        add(tr, a[i], 1);
    }
    LL ans = 0, now = 1;
    for (int i = 1; i <= n; ++i) {
        if (i > m) {
            break;
        }
        int p = ask(tr, b[i] - 1);
        ans = (ans + now * p % mod * fac[n - i]) % mod;
        p = ask(tr, b[i]) - ask(tr, b[i] - 1);
        if (!p) {
            now = 0;
            break;
        }
        now = now * p % mod;
        add(tr, b[i], -1);
    }
    if (n < m) {
        ans = (ans + now) % mod;
    }
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        ++mp[a[i]];
    }
    for (auto [x, y] : mp) {
        ans = ans * qpow(fac[y], mod - 2) % mod;
    }
    cout << ans << endl;

    return 0;
}

/*
1 2
3  
1 2
*/