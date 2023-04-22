#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL qpow(LL q, LL n, LL mod) {
    LL ans = 1 % mod;
    while (n > 0) {
        if (n & 1) {
            ans = ans * q % mod;
        }
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> m >> n;
        int ans = 0;
        while (n--) {
            int a, b;
            cin >> a >> b;
            ans += qpow(a, b, m);
        }
        ans %= m;
        cout << ans << endl;
    }
    return 0;
}