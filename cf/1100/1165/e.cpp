#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int n;
LL a[N], b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i] * i * (n - i + 1);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, greater<LL>());
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i] % mod * b[i] % mod;
    }
    cout << ans % mod << endl;
    return 0;
}