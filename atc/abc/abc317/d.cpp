#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
LL dp[N];

int main() {
    cin >> n;

    int sum = 0;
    vector<PII> a;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x > y) {
            a.push_back({0, z});
        } else {
            a.push_back({(y - x + 1) / 2, z});
        }
        sum += z;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (auto [x, y] : a) {
        for (int i = sum; i >= y; --i) {
            dp[i] = min(dp[i], dp[i - y] + x);
        }
    }
    LL ans = 1e18;
    for (int i = sum / 2 + 1; i <= sum; ++i) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}