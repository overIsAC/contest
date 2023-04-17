#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

int n;
vector<int> edge[N];
vector<int> ve;

void dfs(int x, int fa, int d) {
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x, d + 1);
    }
    if (edge[x].size() == 1) {
        ve.push_back(d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> v >> u;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int ans = 0;
    for (auto &x : edge[1]) {
        ve.clear();
        dfs(x, 1, 1);
        sort(ve.begin(), ve.end());
        for (int i = 1; i < ve.size(); ++i) {
            ve[i] = max(ve[i - 1] + 1, ve[i]);
        }
        ans = max(ans, ve.back());
    }
    cout << ans << endl;
    return 0;
}