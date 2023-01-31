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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int nn = n;
        vector<int> ve(111, 1);
        for (int i = 2; i * i <= nn && i <= n; ++i) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    ++cnt;
                    n /= i;
                }
                for (int j = 0; j < cnt; ++j) {
                    ve[j] *= i;
                }
            }
        }
        if (n > 1) {
            ve[0] *= n;
        }
        int ans = 0;
        for (int i = 0; i < 111; ++i) {
            if (ve[i] == 1) {
                break;
            }
            ans += ve[i];
        }
        cout << ans << endl;
    }
    return 0;
}