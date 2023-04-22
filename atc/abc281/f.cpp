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
const int N = 3 + 3e5;

int n, a[N];
int ans = INT_MAX;
int tr[N * 30][2];
int id;

void insert(int v) {
    int rt = 0;
    for (int i = 29; i >= 0; --i) {
        int &p = tr[rt][v >> i & 1];
        if (!p) {
            p = ++id;
        }
        rt = p;
    }
}

void dfs(int p, int rt, int v) {
    if (v >= ans) {
        return;
    }
    if (p < 0) {
        ans = v;
        return;
    }
    if (tr[rt][0] && tr[rt][1]) {
        dfs(p - 1, tr[rt][0], v | (1 << p));
        dfs(p - 1, tr[rt][1], v | (1 << p));
    } else {
        if (tr[rt][0]) {
            dfs(p - 1, tr[rt][0], v);
        }
        if (tr[rt][1]) {
            dfs(p - 1, tr[rt][1], v);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        insert(a[i]);
    }
    dfs(29, 0, 0);
    cout << ans << endl;
    return 0;
}