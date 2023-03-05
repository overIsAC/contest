#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int len = 1, ans = 0;
        while (len < n) {
            while (len < n && a[n - len] == a[n]) ++len;
            if (len == n) {
                break;
            }
            len = min(n, len * 2);
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}