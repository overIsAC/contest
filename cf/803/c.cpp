#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

LL n, k;

bool ok(LL v) {
    if (n / v >=  k * (k + 1) / 2) return true;
    return false;
}

int main() {
    LL ans = -1;
    cin >> n >> k;
    if (k > n || k > 1e6) {
        cout << -1 << endl;
        return 0;
    }
    for (LL i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (ok(n / i)) {
                ans = n / i;
                break;
            }
            if (ok(i)) {
                ans = i;
            }
        }
    }
    if (ans == -1) {
        cout << ans << endl;
    } else {
        for (int i = 1; i < k; ++i) {
            cout << ans * i << ' ';
            n -= ans * i;
        }
        cout << n << endl;
    }
    return 0;
}