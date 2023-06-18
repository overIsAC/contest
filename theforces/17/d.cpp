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

int n, a[N], k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(1 << k);
    const int MASK = (1 << k) - 1;
    for (int i = 1; i <= n; ++i) {
        vector<int> ndp(1 << k);
        for (int j = i - 1; j >= 1 && i - j <= k; --j) {
            if (gcd(a[i], a[j]) > 1) {
                continue;
            }
            for (int q = 0; q < 1 << k; ++q) {
                int d = i - j;
                if (q >> (d - 1) & 1) {
                    int w = q ^ (1 << (d - 1));
                    w = w << 1 & MASK;
                    ndp[w] = max(ndp[w], dp[q] + 1);
                }
            }
        }
        for (int q = 0; q < 1 << k; ++q) {
            int w = q << 1 & MASK;
            w |= 1;
            ndp[w] = max(ndp[w], dp[q]);
        }
        swap(dp, ndp);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}