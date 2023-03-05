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

int n, a[N];
vector<int> edge[N];
int dp[N][66];

void dfs(int x, int fa) {
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u = i, v;
        cin >> v;
        edge[u].push_back(u);
        edge[v].push_back(v);
    }
    dfs(1, 0);
    return 0;
}