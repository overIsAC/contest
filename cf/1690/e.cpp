#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, k;
int a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += a[i] / k;
            a[i] %= k;
        }
        sort(a + 1, a + n + 1);
        for (int l = 1, r = n; l < r;) {
            if (a[l] + a[r] < k) {
                ++l;
            } else {
                ++l;
                --r;
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}