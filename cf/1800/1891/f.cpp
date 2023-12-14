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
const int N = 3 + 5e5;

struct Node {
    int op, v, x;
    void read() {
        cin >> op >> v;
        if (op == 2) {
            cin >> x;
        }
    }
};

int q, n;
Node a[N];
vector<int> edge[N];
vector<PII> ve[N];
LL tr[N], ans[N];

void add(int p, int v) {
    for (; p >= 1; p -= p & -p) {
        tr[p] += v;
    }
}

LL ask(int p) {
    LL ans = 0;
    for (; p <= n; p += p & -p) {
        ans += tr[p];
    }
    return ans;
}

void dfs(int x) {
    for (auto& [v, p] : ve[x]) {
        add(p, v);
    }
    ans[x] = ask(x);
    for (auto& y : edge[x]) {
        dfs(y);
    }
    for (auto& [v, p] : ve[x]) {
        add(p, -v);
    }
}

void solve() {
    cin >> q;
    n = 1;

    for (int i = 1; i <= q; ++i) {
        a[i].read();
        if (a[i].op == 1) {
            ++n;
            edge[a[i].v].push_back(n);
        } else {
            ve[a[i].v].push_back({a[i].x, n});
        }
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
        ve[i].clear();
        tr[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}