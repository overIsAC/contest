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
const int N = 3 + 2e5;

int dp[2][N];
int n, k;
LL ans[N];

int main() {
    cin >> n >> k;
    **dp = 1;
    int *u = dp[0], *v = dp[1];
    for (int j = 1; j < 640; ++j) {
        memset(v, 0, sizeof(dp[0]));
        for (int i = j - 1 + k; i <= n; ++i) {
            v[i] = (u[i - (j - 1 + k)] + v[i - (j - 1 + k)]) % mod;
            ans[i] += v[i];
        }
        swap(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] % mod << ' ';
    }

    return 0;
}