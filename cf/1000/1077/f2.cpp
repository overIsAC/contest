#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e3;

int n, k, x;
int a[N];
LL dp[N][N];

int main() {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int j = 1; j <= n; ++j) {
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i <= n; ++i) {
            if (dq.size()) {
                dp[i][j] = max(dp[i][j], dp[dq.front()][j - 1] + a[i]);
            }
            while (dq.size() && i - dq.front() >= k) {
                dq.pop_front();
            }
            while (dq.size() && dp[dq.back()][j - 1] < dp[i][j - 1]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
    }
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= x; ++j) {
    //         cout << max(dp[i][j], -1LL) << ' ';
    //     }
    //     cout << endl;
    // }
    LL ans = -1;
    for (int i = n - k + 1; i <= n; ++i) {
        ans = max(ans, dp[i][x]);
    }
    cout << ans << endl;

    return 0;
}