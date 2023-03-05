#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
LL a[N];

void solve() {
    LL suffix = 0, ans = 0, now = a[1];
    for (int i = 2; i <= n; ++i) {
        a[i] -= suffix;
        if (now == a[i]) continue;
        ans += abs(a[i] - now);
        if (a[i] > now) {
            suffix += a[i] - now;
        } else {
            now = a[i];
        }
    }
    ans += abs(now);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}