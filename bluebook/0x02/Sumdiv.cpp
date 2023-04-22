#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 9901;

int a, b;

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * q % mod;
        }
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

LL qgeo(LL q, LL n) {
    if (!n) {
        return 1;
    }
    LL ans = 0;
    if (n % 2 == 0) {
        ans += qpow(q, n);
        --n;
    }
    ans += qgeo(q, n / 2) * (1 + qpow(q, n / 2 + 1));
    return ans % mod;
}

int main() {
    cin >> a >> b;
    int ans = 1;
    if (!a) {
        ans = 0;
    }
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            int cnt = 0;
            while (a % i == 0) {
                a /= i;
                ++cnt;
            }
            ans = ans * qgeo(i, (LL)cnt * b) % mod;
        }
    }
    if (a > 1) {
        ans = ans * qgeo(a, b) % mod;
    }
    cout << ans << endl;
    return 0;
}