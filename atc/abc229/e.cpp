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
const int N = 3 + 2e5;

int n, m;
vector<int> edge[N];

int fa[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        edge[u].push_back(v);
    }
    vector<int> ans;
    int now = 0;
    for (int i = n; i >= 1; --i) {
        ans.push_back(now);
        ++now;
        for (auto &j : edge[i]) {
            if (find(i) == find(j)) {
                continue;
            }
            --now;
            fa[find(i)] = find(j);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto &i : ans) {
        cout << i << endl;
    }
    return 0;
}