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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 6e3;

int dp[N][N];
LL n;
vector<LL> p;
vector<LL> fac[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        p.clear();
        memset(dp, 0, sizeof(dp));

        cin >> n;
        for (LL i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                p.push_back(i);
                if (i * i != n) {
                    p.push_back(n / i);
                }
            }
        }
        sort(p.begin(), p.end());
        dp[0][0] = 1;
        for (int i = 1; i < p.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (p[i] % p[j]) {
                    continue;
                }
                fac[j].push_back(i);
                for (int k = j; k <= i; ++k) {
                    if ((p[i] / p[k]) <= (p[k] / p[j])) {
                        break;
                    }
                    if (p[i] % p[k]) {
                        continue;
                    }
                    dp[i][k] += dp[k][j];
                    if (dp[i][k] >= mod) {
                        dp[i][k] -= mod;
                    }
                }
            }
        }
        LL ans = 0;
        for (int i = 1; i < p.size(); ++i) {
            ans += dp[p.size() - 1][i];
        }
        ans %= mod;
        cout << ans << endl;
    }

    return 0;
}