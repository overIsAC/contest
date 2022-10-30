#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    LL ans = a[n] - a[1];
    for (int i = 2, j = n - 1; i <= j; ++i, --j) {
        ans += a[n] - a[1];
        if (i == j) break;
        ans += a[n] - a[1];
    }
    cout << ans << endl;
    return 0;
}