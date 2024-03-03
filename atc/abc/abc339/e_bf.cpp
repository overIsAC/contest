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
const int N = 3 + 1e5;

int n, a[N];
int dp[N];  // dp[i] 就是 以第i个数为结尾的子序列

int main() {
    int n, d;
    cin >> n >> d;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            if (abs(a[i] - a[j]) <= d) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;

    // 不确定哪个dp值比较大， 需要for一遍
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans + 1 << endl;
    return 0;
}