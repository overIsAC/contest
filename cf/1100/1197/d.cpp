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
const int N = 3 + 3e5;

int n, m, k;
int a[N];
LL pre[N], dp[N];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i >= j) {
                ans = max(ans, dp[i - j] + pre[i] - pre[i - j] - (LL) (j + m - 1) / m * k);
            }
        }
        if (i >= m) {
            dp[i] = max(dp[i], dp[i - m] + pre[i] - pre[i - m] - k);
        }
    }
    cout << ans << endl;

    return 0;
}