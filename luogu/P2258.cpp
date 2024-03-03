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
const int N = 2 + 20;

int n, m, r, c;
int a[N][N];
int dp[N][N];

int solve(int st) {
    int z = 0;
    for (int i = 0; i < m; ++i) {
        if (st >> i & 1) {
            ++z;
        }
    }
    if (z != c) {
        return 1e9;
    }
    vector<int> b;

    for (int i = 0; i < n; ++i) {
        int c = 0, last = 0;
        for (int j = 0; j < m; ++j) {
            if (st >> j & 1) {
                if (last) {
                    c += abs(last - a[i][j]);
                }
                last = a[i][j];
            }
        }
        b.push_back(c);
    }

    memset(dp, 0x3f, sizeof(dp));

    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        dp[i][1] = b[i];
        for (int j = 0; j < i; ++j) {
            int z = 0;
            for (int k = 0; k < m; ++k) {
                if (st >> k & 1) {
                    z += abs(a[i][k] - a[j][k]);
                }
            }

            for (int k = 2; k <= r; ++k) {
                dp[i][k] = min(dp[j][k - 1] + z + b[i], dp[i][k]);
            }
        }
        ans = min(ans, dp[i][r]);
    }

    return ans;
}

int main() {
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 1 << m; ++i) {
        ans = min(ans, solve(i));
    }
    cout << ans << endl;

    return 0;
}