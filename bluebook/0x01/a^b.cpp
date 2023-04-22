#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a, b, p;

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
    cin >> a >> b >> p;
    cout << qpow(a, b, p) << endl;
    return 0;
}