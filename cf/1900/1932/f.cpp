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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<PII> a(m);
    for (auto& [u, v] : a) {
        cin >> u >> v;
    }
    vector<vector<int>> ve(n + 1);
    vector<int> b(n + 2), c(n + 1);
    for (auto& [u, v] : a) {
        b[u] += 1;
        b[v + 1] -= 1;
        c[u] = max(c[u], v);
    }
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
        c[i] = max(c[i], c[i - 1]);
    }
    vector<int> tr(n + 1);
    int ans = 0;

    auto add = [&](int p, int v) {
        for (; p <= n; p += p & -p) {
            tr[p] = max(tr[p], v);
        }
    };
    auto ask = [&](int p) {
        int ans = 0;
        for (; p; p -= p & -p) {
            ans = max(ans, tr[p]);
        }
        return ans;
    };

    for (int i = 1; i <= n; ++i) {
        int z = ask(i) + b[i];
        ans = max(ans, z);
        if (c[i] >= i && c[i] + 1 <= n) {
            add(c[i] + 1, z);
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}