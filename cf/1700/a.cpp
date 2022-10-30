#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        LL ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans += i;
        }
        for (int i = 2; i <= n; ++i) {
            ans += (i - 1) * m + m;
        }
        cout << ans << endl;
    }
    return 0;
}