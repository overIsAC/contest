#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
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

int n, k, a[55];
LL dp[55][2555];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        for (int j = sum; j >= a[i]; --j) {
            for (int k = i; k > 0; --k) {
                dp[k][j] += dp[k - 1][j - a[i]];
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i][i * k];
    }
    cout << ans << endl;
    return 0;
}