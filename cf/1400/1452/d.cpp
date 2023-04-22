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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e5;

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
    int n;
    cin >> n ;
    LL ans = 0;
    for (int i = 1, j = n; i <= j; ++i, --j) {
        int cnt = i;
        cnt += (n - j + 1);
        if (i == j) {
            --cnt;
        }
        ans += qpow(qpow(2, cnt), mod - 2);
    }
    ans %= mod;
    cout << ans << endl;
    return 0;
}