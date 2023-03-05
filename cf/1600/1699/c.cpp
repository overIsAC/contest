#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
int p[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0) {
                l = r = i;
            }
            p[a[i]] = i;
        }
        LL ans = 1;
        for (int i = 1; i < n; ++i) {
            if (l <= p[i] && p[i] <= r) {
                ans *= r - l + 1 - i;
                ans %= mod;
            } else {
                l = min(l, p[i]);
                r = max(r, p[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}