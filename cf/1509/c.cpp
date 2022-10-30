#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e3;

int n, a[N];
LL dp[N][N];

LL dfs(int l, int r) {
    if (l == r) {
        return 0;
    }
    LL &v = dp[l][r];
    if (v != -1) return v;
    v = min(dfs(l, r - 1), dfs(l + 1, r)) + a[r] - a[l];
    return v;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof(dp));

    cout << dfs(1, n) << endl;

    return 0;
}