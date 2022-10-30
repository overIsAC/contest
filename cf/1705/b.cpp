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
        }
        LL ans = 0;
        LL sum = 0;
        for (int i = 1; i < n; ++i) {
            if (!a[i] && sum) {
                ans += 1;
            }
            sum += a[i];
        }
        ans += sum;
        cout << ans << endl;
    }
    return 0;
}