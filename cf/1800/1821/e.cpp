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
const int N = 3 + 1e5;

int k;
string s;
int n;
vector<int> edge[N];
int sz[N];
LL dp[N][8];
LL temp[8];

void dfs(int x) {
    sz[x] = 1;
    for (auto &y : edge[x]) {
        dfs(y);
        sz[x] += sz[y];
    }
    memset(dp[x], 0, sizeof(dp[x]));
    if (x) {
        dp[x][0] = sz[x] - 1;
    }
    for (auto &y : edge[x]) {
        memset(temp, 0x3f, sizeof(temp));
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; i + j <= k; ++j) {
                temp[i + j] = min(temp[i + j], dp[x][i] + dp[y][j]);
            }
        }
        memcpy(dp[x], temp, sizeof(temp));
    }
}

void solve() {
    cin >> k;
    cin >> s;
    stack<int> stk;
    for (auto &i : s) {
        if (i == '(') {
            stk.push(++n);
        } else {
            int p = stk.top();
            stk.pop();
            if (stk.size()) {
                edge[stk.top()].push_back(p);
            } else {
                edge[0].push_back(p);
            }
        }
    }
    dfs(0);

    LL ans = 1e18;
    for (int i = 0; i <= k; ++i) {
        ans = min(dp[0][i], ans);
    }
    cout << ans << endl;

    for (int i = 0; i <= n; ++i) {
        edge[i].clear();
    }
    n = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
(())(())

*/