#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    LL ans = 0;
    for (int i = 1, j = n; i <= j; ++i) {
        LL sum = 0;
        while (i < j && a[i] > sum) {
            sum += a[j];
            --j;
        }
        if (sum == a[i]) {
            ans += 1 + sum;
            continue;
        }
        if (sum > a[i]) {
            ++j;
            ans += 1 + a[i];
            a[j] = sum - a[i];
        } else {
            sum += a[j--];
            if (sum == 1) {
                ans += 1;
            } else {
                ans += (sum + 1) / 2 + 1;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}