#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int pre1[N], suf1[N], a[N];
int pre2[N], suf2[N];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (is_sorted(a + 1, a + n + 1)) {
        cout << 0 << endl;
        return;
    }
    if (is_sorted(a + 1, a + n + 1,greater<int>())) {
        cout << 1 << endl;
        return;
    }

    pre1[1] = pre2[1] = 1;
    suf1[n] = suf2[n] = 1;
    for (int i = 2; i <= n; ++i) {
        pre1[i] = (pre1[i - 1] && a[i - 1] <= a[i]);
        pre2[i] = (pre2[i - 1] && a[i - 1] >= a[i]);
    }
    for (int i = n - 1; i >= 1; --i) {
        suf1[i] = (suf1[i + 1] && a[i] <= a[i + 1]);
        suf2[i] = (suf2[i + 1] && a[i] >= a[i + 1]);
    }
    int ans = INT_MAX;

    for (int i = 1; i < n; ++i) {
        if (pre1[i] && suf1[i + 1] && a[n] <= a[1]) {
            ans = min(ans, i + 2);
            ans = min(ans, n - i);
        }
        if (pre2[i] && suf2[i + 1] && a[1] <= a[n]) {
            ans = min(ans, i + 1);
            ans = min(ans, n - i + 1);
        }
    }

    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}