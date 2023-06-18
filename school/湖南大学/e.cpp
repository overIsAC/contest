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

int n, k, a[N];
int dp[N][2];

int dfs(int p, int v) {
    if (p == n + 1) {
        return 0;
    }
    int &ans = dp[p][v];
    if (ans >= 0) {
        return ans;
    }
    if (!dfs(p + 1, a[p + 1] > 1)) {
        return ans = 1;
    }
    if (v && !dfs(p, 0)) {
        return ans = 1;
    }
    return ans = 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) { 
            cin >> a[i];
        }
        for (int i = 0; i <= n + 1; ++i) {
            memset(dp[i], -1, sizeof(dp[i]));
        }
        if (dfs(1, a[1] > 1)) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }

    return 0;
}