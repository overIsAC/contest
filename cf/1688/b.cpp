#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            int b = 0;
            while (a[i] % 2 == 0) {
                ++b;
                a[i] >>= 1;
            }
            a[i] = b;
        }
        sort(a + 1, a + n + 1);

        int ans = 0;

        int q = 1;
        while (q + 1 <= n && a[q + 1] == a[1]) ++q;
        ans += a[1];
        ans += n - 1;
        if (a[1] == 0) {
            ans -= q - 1;
        }
        cout << ans << endl;
    }
    return 0;
}