#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, k, a[N];
LL pre[N];

void solve() {
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    if (k <= n) {
        LL ans = 0;
        for (int i = k; i <= n; ++i) {
            ans = max(ans, pre[i] - pre[i - k]);
        }
        ans += (LL)(k - 1) * k / 2;
        cout << ans << endl;
        return;
    }
    cout << pre[n] + (LL)n * (k - n + k - 1) / 2 << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}