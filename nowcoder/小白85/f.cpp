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
const int N = 3 + 5e3;

int n, l, r, a[N];
int dp[N][N];

int main() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    for (int i = 0; i <= a[1]; ++i) {
        if (l <= i && i <= r) {
            dp[1][i] = 1;
        } else {
            dp[1][i] = 0;
        }
    }
    for (int i = 2; i <= n; ++i) {
        int z = -1e9, w = 0;
        for (int j = a[i - 1]; j >= 0; --j) {
            w = a[i - 1] - j;
            w = a[i] - w;
            w = max(w, 0);

            z = max(dp[i - 1][j], z);
            dp[i][w] = max(dp[i][w], z);
        }
        while (w >= 0) { 
            dp[i][w] = max(dp[i][w], z);
            --w;
        }
        for (int j = 0; j <= a[i]; ++j) {
            if (l <= j && j <= r) {
                dp[i][j] += 1;
            }
        }
    }
    cout << *max_element(dp[n], dp[n] + a[n] + 1) << endl;
    return 0;
}