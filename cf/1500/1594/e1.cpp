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
const int N = 3 + 1e5;

int main() {
    int k;
    cin >> k;
    vector<LL> dp(6, 1);
    for (int i = 1; i < k; ++i) {
        vector<LL> d(6, 0);
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                if ((j - k + 6) % 6 % 3 == 0) {
                    continue;
                }
                for (int q = 0; q < 6; ++q) {
                    if ((j - q + 6) % 6 % 3 == 0) {
                        continue;
                    }
                    d[j] = (d[j] + dp[k] * dp[q]) % mod;
                }
            }
        }
        swap(d, dp);
    }
    cout << accumulate(dp.begin(), dp.end(), 0LL) % mod << endl;
    return 0;
}