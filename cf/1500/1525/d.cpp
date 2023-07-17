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
const int N = 3 + 5555;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b[2];
    for (int i = 1; i <= n; ++i) {
        b[a[i]].push_back(i);
    }
    if (b[1].empty()) {
        cout << 0 << endl;
        return 0;
    }
    int u = b[0].size(), v = b[1].size();
    vector dp(u + 1, vector<LL>(v + 1, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= u; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= u; ++i) {
        for (int j = 1; j <= i && j <= v; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(b[0][i - 1] - b[1][j - 1]));
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    }
    LL ans = 1e18;
    for (int i = v; i <= u; ++i) {
        ans = min(ans, dp[i][v]);
    }
    cout << ans << endl;
    return 0;
}

/*
3
0 0 1

*/