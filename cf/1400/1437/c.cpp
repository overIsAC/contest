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
const int N = 3 + 200;

int dp[N][N * 2];
int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        memset(dp, 0x3f, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 2 * n; ++j) {
                for (int k = j + 1; k <= 2 * n; ++k) {
                    dp[i][k] = min(dp[i - 1][j] + abs(a[i] - k), dp[i][k]);
                }
            }
        }
        cout << *min_element(dp[n], dp[n] + 2 * n + 1) << endl;
    }
    return 0;
}