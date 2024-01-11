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

int n, ls[N], rs[N], val[N];
int sz[N];
int ans;

int cmp(int x, int y) {
    if (val[x] != val[y]) {
        return 0;
    }
    if (!ls[x] && rs[y]) {
        return 0;
    }
    if (ls[x] && !rs[y]) {
        return 0;
    }
    if (!rs[x] && ls[y]) {
        return 0;
    }
    if (rs[x] && !ls[y]) {
        return 0;
    }
    if (ls[x] && rs[y]) {
        if (!cmp(ls[x], rs[y])) {
            return 0;
        }
    }
    if (rs[x] && ls[y]) {
        if (!cmp(rs[x], ls[y])) {
            return 0;
        }
    }
    return 1;
}

void dfs(int x) {
    if (!x) {
        return;
    }
    dfs(ls[x]);
    dfs(rs[x]);
    sz[x] = sz[ls[x]] + sz[rs[x]] + 1;

    if (sz[x] == 1) {
        ans = max(ans, 1);
    } else {
        if (cmp(ls[x], rs[x])) {
            ans = max(ans, sz[x]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> ls[i] >> rs[i];
        if (ls[i] == -1) {
            ls[i] = 0;
        }
        if (rs[i] == -1) {
            rs[i] = 0;
        }
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}