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
const int N = 3 + 111;

int n, d[N][N];
LL ans;
LL dp[1 << 20];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }

    for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >> j & 1) {
                continue;
            }
            for (int k = 0; k < n; ++k) {
                if (i >> k & 1) {
                    continue;
                }
                int w = i | (1 << j) | (1 << k);
                dp[w] = max(dp[w], dp[i] + d[j][k]);
            }
        }
    }

    cout << *max_element(dp, dp + (1 << 20)) << endl;

    return 0;
}