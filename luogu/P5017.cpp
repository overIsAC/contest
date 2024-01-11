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
const int N = 3 + 500;
const int M = 5000 ;

int n, m, t[N];
LL preCnt[M], preWait[M];
LL dp[M];

LL calc(int l, int r) {
    LL ans = preWait[r];
    if (l > 0) {
        ans -= preWait[l - 1];
        ans -= preCnt[l - 1] * (r - l + 1);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; ++i) {
        ++preCnt[t[i]];
    }
    for (int i = 1; i < M; ++i) {
        preCnt[i] += preCnt[i - 1];
        preWait[i] = preWait[i - 1] + preCnt[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < M; ++i) {
        for (int j = 1; j <= n && i - j + 1 >= 1; ++j) {
            dp[i] = min(dp[i], dp[i - j] + calc(i - j + 1, i));
        }
    }
    cout << dp[M - 1] << endl;
    return 0;
}