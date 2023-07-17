#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int mod = 7 + 1e9;

LL f(int x) {
    LL ans = 1;
    while (x) {
        ans = ans * (x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 > 20) {
            cout << 0 << endl;
        } else {
            LL ans = 1;
            for (int i = l; i <= r; ++i) {
                ans = ans * f(i) % mod;
            }
            cout << ans << endl;
        }
    }
    return 0;
}