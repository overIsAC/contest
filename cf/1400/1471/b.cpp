#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e6;

int n, a[N], x;
int b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += a[i];
            b[i] = a[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (b[i] % x == 0) {
                b[++n] = b[i] / x;
                ans += a[i];
                a[n] = a[i];
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}