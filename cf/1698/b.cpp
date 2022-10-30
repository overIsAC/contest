#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], k;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (a[i] > a[i - 1] + a[i + 1]) {
                ++ans;
            }
        }
        if (k == 1) {
            ans = n / 2;
            if (n % 2 == 0) {
                ans -= 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}