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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int n, k;
LL dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    dp[0] = 1;
    while (n--) {
        char op;
        int w;
        cin >> op >> w;
        if (op == '+') {
            for (int i = k; i >= w; --i) {
                dp[i] = (dp[i] + dp[i - w]) % mod;
            }
        } else {
            for (int i = w; i <= k; ++i) {
                dp[i] = (dp[i] - dp[i - w]) % mod;
            }
        }
        cout << (dp[k] + mod) % mod << '\n';
    }
    return 0;
}