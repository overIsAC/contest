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

int n, k;
int a[N];
LL dp[N][33];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 32; ++j) {
                dp[i][j] = -1e18;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            int z = a[i];
            for (int j = 0; j <= 32; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + z - k);
                if (j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + z);
                }

                z /= 2;
            }
            dp[i][32] = max(dp[i][32], dp[i - 1][32]);
        }
        cout << *max_element(dp[n], dp[n] + 33) << endl;
    }

    return 0;
}