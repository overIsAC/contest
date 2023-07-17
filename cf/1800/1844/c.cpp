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
LL dp[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        LL cnt[2];
        cnt[0] = -1e18;
        cnt[1] = -1e18;
        for (int i = 1; i <= n; ++i) {
            dp[i] = max(0LL, cnt[i & 1]) + a[i];
            cnt[i & 1] = max(dp[i], cnt[i & 1]);
        }
        cout << *max_element(dp + 1, dp + n + 1) << endl;
    }
    return 0;
}