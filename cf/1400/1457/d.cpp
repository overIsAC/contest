#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
int pre[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] ^ a[i];
    }
    if (n > 60) {
        cout << 1 << endl;
        return 0;
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (i - 1 >= 1 && (pre[j] ^ pre[i - 1]) < a[i - 1]) {
                ans = min(ans, j - i);
            }
            if (j + 1 <= n && (pre[j] ^ pre[i - 1]) > a[j + 1]) {
                ans = min(ans, j - i);
            }
            for (int k = i; k < j; ++k) {
                int l1 = i, r1 = k;
                int l2 = k + 1, r2 = j;
                if ((pre[l1 - 1] ^ pre[r1]) > (pre[l2 - 1] ^ pre[r2])) {
                    ans = min(r2 - l2 + r1 - l1, ans);
                }
            }
        }
    }
    if (n == ans) ans = -1;
    cout << ans << endl;
    return 0;
}