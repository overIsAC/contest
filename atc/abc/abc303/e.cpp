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

vector<int> edge[N];
int n;
int d[N], du[N];

void dfs(int x, int fa) {
    d[x] = d[fa] + 1;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        du[i] = edge[i].size();
        if (du[i] == 1) {
            q.push(i);
            d[i] = 1;
        }
    }
    while (q.size()) {
        auto x = q.front();
        q.pop();
        for (auto &y : edge[x]) {
            if (--du[y] == 1) {
                q.push(y);
                d[y] = d[x] + 1;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (d[i] % 3 == 2) {
            ans.push_back(edge[i].size());
        }
    }
    sort(ans.begin(), ans.end());
    for (auto &i : ans) {
        cout << i << ' ';
    }
    return 0;
}