#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 5e5;

int n, a[N];
LL cnt1[N], cnt2[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i <= n + 1; ++i) {
            cnt1[i] = 0;
            cnt2[i] = 0;
        }
        cnt1[0] = 1;
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += cnt1[a[i]];
            ans += cnt1[a[i] + 1];
            ans += cnt2[a[i] + 1];
            if (a[i]) {
                ans += cnt1[a[i] - 1];
                ans += cnt2[a[i] - 1];
            }

            cnt1[a[i] + 1] += cnt1[a[i] + 1];
            cnt1[a[i] + 1] += cnt1[a[i]];
            cnt1[a[i] + 1] %= mod;

            cnt2[a[i] + 1] += cnt2[a[i] + 1];
            cnt2[a[i] + 1] %= mod;
            if (a[i]) {
                cnt2[a[i] - 1] += cnt1[a[i] - 1] + cnt2[a[i] - 1];
                cnt2[a[i] - 1] %= mod;
            }

            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}