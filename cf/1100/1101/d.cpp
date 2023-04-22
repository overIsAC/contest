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

int a[N], n;
vector<int> edge[N];
map<int, int> mp[N];
int ans;

void dfs(int x, int fa) {
    if (a[x] > 1) {
        mp[x][a[x]] = 1;
        ans = max(ans, 1);
    }
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
        for (auto &i : mp[x]) {
            for (auto &j : mp[y]) {
                if (i.second + j.second <= ans) {
                    continue;
                }
                if (__gcd(i.first, j.first) > 1) {
                    ans = i.second + j.second;
                }
            }
        }
        for (auto &i : mp[y]) {
            int g = __gcd(i.first, a[x]);
            if (g > 1) {
                mp[x][g] = max(mp[x][g], i.second + 1);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}