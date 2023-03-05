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
    int T, a, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = 1 << 20;
        ans -= 1;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            if (i != a) ans &= a;
        }
        cout << ans << endl;
    }
    return 0;
}