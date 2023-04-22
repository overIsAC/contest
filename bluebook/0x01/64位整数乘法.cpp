#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a, b, p;

LL qmul(LL a, LL b, LL mod) {
    LL ans = 0;
    while (b > 0) {
        if (b & 1) {
            ans = (ans + a) % mod;
        }
        a = a * 2 % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    cin >> a >> b >> p;
    cout << qmul(a, b, p) << endl;
    return 0;
}