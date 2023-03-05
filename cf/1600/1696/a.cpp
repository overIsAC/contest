#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], z;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> z;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ans = max(z | a[i], ans);
        }
        cout << ans << endl;
    }
    return 0;
}