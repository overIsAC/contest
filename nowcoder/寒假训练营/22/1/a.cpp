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
const int N = 3 + 1e5;

int n, a[N];
LL dp[N][10];

int get(int x) {
    if (x <= 9) {
        return x;
    }
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return get(ans);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int v = get(a[i]);
        ++dp[i][v];
        for (int j = 1; j <= 9; ++j) {
            dp[i][get(j + v)] += dp[i - 1][j];
        }
        for (int j = 1; j <= 9; ++j) {
            dp[i][j] %= mod;
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }
    for (int i = 1; i <= 9; ++i) {
        cout << dp[n][i] << ' ';
    }
    return 0;
}