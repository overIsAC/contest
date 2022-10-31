#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, x, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int mn = a[i], mx = a[i];
            int j = i;
            while (j + 1 <= n &&
                   max(mx, a[j + 1]) - min(mn, a[j + 1]) <= 2 * x) {
                j += 1;
                mx = max(mx, a[j]);
                mn = min(mn, a[j]);
            }
            ++ans;
            i = j;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}