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

int n, p[N];
vector<int> edge[N];
int mn[N], mx[N];
int pre[N];

void dfs(int x) {
    for (auto &y : edge[x]) {
        dfs(y);
        mn[x] = min(mn[y], mn[x]);
        mx[x] = max(mx[y], mx[x]);
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int u, v;
        cin >> u;
        v = i;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        mn[p[i]] = i;
        mx[p[i]] = i;
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        // cout << i << ' ' << mn[i] << ' ' << mx[i] << endl;
        ++pre[mn[i]];
        --pre[mx[i]];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
        cout << pre[i] << ' ';
    }
    return 0;
}