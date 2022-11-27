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
const int N = 3 + 1e5;

int c[N];
int f[N];
int l, r;

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
    cin >> l >> r;
    bool ok = false;
    for (int i = 2; i <= r; ++i) {
        if (f[i]) {
            continue;
        }
        for (int j = i + i; j <= r; j += i) {
            f[j] = 1;
            if (j >= l) {
                int v = j;
                ok = true;
                int cnt = 0;
                while (v % i == 0) {
                    ++cnt;
                    v /= i;
                }
                c[i] = max(c[i], cnt);
            }
        }
    }
    LL ans = 1;
    for (int i = 2; i <= r; ++i) {
        ans = ans * qpow(i, c[i]) % mod;
    }
    if (!ok) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}