#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];
int stk[N], top;
LL pre[N];
int ls[N], rs[N];
bool ok;
LL mn[N], mx[N];

void dfs(int x) {
    mn[x] = pre[x - 1];
    mx[x] = pre[x];
    if (ls[x]) {
        dfs(ls[x]);
        mn[x] = min(mn[x], mn[ls[x]]);
    }
    if (rs[x]) {
        dfs(rs[x]);
        mx[x] = max(mx[x], mx[rs[x]]);
    }
    if (a[x] + mn[x] < mx[x]) {
        ok = false;
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }

    top = 0;
    for (int i = 1; i <= n; ++i) {
        ls[i] = rs[i] = 0;

        int k = top;
        while (k && a[stk[k]] < a[i]) --k;
        if (k < top) ls[i] = stk[k + 1];
        rs[stk[k]] = i;
        stk[++k] = i;
        top = k;
    }

    ok = true;
    dfs(rs[0]);

    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}