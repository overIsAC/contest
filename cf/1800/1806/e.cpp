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

vector<int> edge[N];
int n, q, a[N];
int d[N], fa[N];
LL mp[N][400];
LL cnt[N];
int id[N];

void dfs(int x) {
    cnt[d[x]] += 1;
    id[x] = cnt[d[x]];
    for (int &y : edge[x]) {
        d[y] = d[x] + 1;
        fa[y] = x;
        dfs(y);
    }
}

LL solve(int x, int y) {
    if (!x) {
        return 0;
    }
    if (x > y) {
        swap(x, y);
    }
    if (id[y] < 400 && mp[x][id[y]]) {
        return mp[x][id[y]];
    }
    LL ans = solve(fa[x], fa[y]) + (LL)a[x] * a[y];
    if (id[y] < 400) {
        mp[x][id[y]] = ans;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        int u, v;
        cin >> u;
        v = i;
        edge[u].push_back(v);
    }
    dfs(1);
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << '\n';
    }

    return 0;
}