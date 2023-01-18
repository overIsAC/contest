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

vector<int> edge[N];
int n;
int stk[N], *top = stk;
int *f[N];
int d[N], md[N], son[N];
int ans[N];

void dfs1(int x, int fa) {
    d[x] = d[fa] + 1;
    md[x] = d[x];
    for (int &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs1(y, x);
        md[x] = max(md[x], md[y]);
        if (md[son[x]] < md[y]) {
            son[x] = y;
        }
    }
}

void dfs2(int x, int fa) {
    ++f[x][0];
    if (son[x]) {
        f[son[x]] = f[x] + 1;
        dfs2(son[x], x);
        ans[x] = ans[son[x]] + 1;
    }
    for (int &y : edge[x]) {
        if (y == fa || y == son[x]) {
            continue;
        }
        f[y] = top;
        top += md[y] - d[y] + 1;
        dfs2(y, x);
        for (int i = 0; i <= md[y] - d[y]; ++i) {
            f[x][i + 1] += f[y][i];
            if (f[x][ans[x]] < f[x][i + 1] || f[x][ans[x]] == f[x][i + 1] && ans[x] > i + 1) {
                ans[x] = i + 1;
            }
        }
    }
    if (f[x][ans[x]] == 1) {
        ans[x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(1, 0);
    f[1] = top;
    top += md[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}