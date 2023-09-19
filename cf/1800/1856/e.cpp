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
const int N = 3 + 1e6;

int sz[N], n;
vector<int> edge[N];
LL ans;

void addEdge(int u, int v) {
    edge[u].push_back(v);
}

LL knapsack(vector<int> &w, int n) {
    map<int, int> mp;
    for (auto &i : w) {
        if (i * 2 >= n) {
            return (LL)i * (n - i);
        }
        ++mp[i];
    }
    vector<int> dp(n + 1);
    int sum = 0;
    dp[0] = 1;
    for (auto [x, y] : mp) {
        for (int i = 1; i <= y; y -= i, i *= 2) {
            for (int j = sum; j >= 0; --j) {
                if (dp[j]) {
                    dp[j + i * x] = 1;
                }
            }
            sum += i * x;
        }
        if (y) {
            for (int j = sum; j >= 0; --j) {
                if (dp[j]) {
                    dp[j + y * x] = 1;
                }
            }
            sum += y * x;
        }
    }
    LL ans = 0;
    for (int i = (n + 1) / 2; i >= 1; --i) {
        if (dp[i]) {
            ans = max(ans, (LL)i * (n - i));
            break;
        }
    }
    return ans;
}

void dfs(int x, int fa) {
    sz[x] = 1;
    vector<int> w;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        w.push_back(sz[y]);
        sz[x] += sz[y];
    }
    ans += knapsack(w, sz[x] - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        addEdge(p, i);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}