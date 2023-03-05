#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e6;

int n, a[N], m;
int b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; ++i) {
            cin >> b[i];
        }
        LL ans = 0;
        sort(a + 1, a + n + 1);
        int p = 1;
        for (int i = n; i; --i) {
            if (p > m || b[p] >= b[a[i]]) {
                ans += b[a[i]];
            } else {
                ans += b[p++];
            }
        }
        cout << ans << endl;
    }
    return 0;
}