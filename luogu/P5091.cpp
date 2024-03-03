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

int a, m;
string b;

int phi(int n) {
    LL ans = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            ans = ans / i * (i - 1);
        }
    }
    if (n > 1) {
        ans = ans / n * (n - 1);
    }
    return ans;
}

LL qpow(LL q, LL n, LL mod) {
    LL ans = 1 % mod;
    while (n) {
        if (n & 1)
            ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    cin >> a >> m >> b;
    int p = phi(m);
    int c = 0;

    int g = 0;
    for (auto& i : b) {
        c = c * 10 + i - '0';
        if (c >= p) {
            g = 1;
            c %= p;
        }
    }
    if (g) {
        c += p;
    }
    cout << qpow(a, c, m) << endl;
    return 0;
}