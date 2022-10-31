#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, k, a[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = n, ans = 0;
    while (true) {
        if (l <= r && a[l] <= k) {
            ++l;
            ++ans;
            continue;
        }
        if (l <= r && a[r] <= k) {
            --r;
            ++ans;
            continue;
        }
        break;
    }
    cout << ans << endl;
    return 0;
}