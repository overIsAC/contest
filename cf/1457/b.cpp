#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, k, a[N];

void solve() {
    int ans = n;
    for (int i = 1; i <= 100; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[j] == i) continue;
            ++cnt;
            j += k - 1;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
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