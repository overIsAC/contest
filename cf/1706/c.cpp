#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 5 + 1e5;

int n, a[N];
LL pre[N], suf[N];

LL calc(int p) {
    LL ans = 0;
    for (int i = p; i < n; i += 2) {
        ans += max(a[i - 1], a[i + 1]) + 1 - a[i];
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        suf[n + 1] = suf[n + 2] = 0;
        for (int i = 2; i < n; i += 2) {
            pre[i] = pre[i - 2] + max(0, max(a[i - 1], a[i + 1]) + 1 - a[i]);
        }
        for (int i = n - 1; i > 1; i -= 2) {
            suf[i] = suf[i + 2] + max(0, max(a[i - 1], a[i + 1]) + 1 - a[i]);
        }
        LL ans = LLONG_MAX;
        if (n % 2 == 0) {
            ans = min(pre[n - 2], suf[3]);
            for (int i = 3; i < n; i += 2) {
                if (i + 2 <= n) ans = min(ans, pre[i - 1] + suf[i + 2]);
            }
        } else {
            ans = pre[n - 1];
        }
        cout << ans << endl;
    }
    return 0;
}