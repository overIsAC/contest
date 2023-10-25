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

int n, a[N];
int f[20][N];
int d[N];
vector<int> edge[N];
int one[30][N];
int _lg[N];
vector<int> ne[N];

void dfs(int x, int fa, vector<int> t) {
    d[x] = d[fa] + 1;
    f[0][x] = fa;

    for (int i = 1; i < 20; ++i) {
        f[i][x] = f[i - 1][f[i - 1][x]];
    }
    for (int i = 0; i < 30; ++i) {
        one[i][x] = one[i][fa] + (a[x] >> i & 1);
        if (a[x] >> i & 1) {
            t[i] = x;
        }
    }
    ne[x] = t;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x, t);
    }
}

int lca(int x, int y) {
    if (d[x] > d[y]) {
        swap(x, y);
    }
    for (int i = _lg[d[y] - d[x]]; i >= 0; --i) {
        if (d[x] <= d[f[i][y]]) {
            y = f[i][y];
        }
    }
    if (x == y) {
        return x;
    }
    for (int i = _lg[d[x]]; i >= 0; --i) {
        if (f[i][x] != f[i][y]) {
            x = f[i][x];
            y = f[i][y];
        }
    }
    return f[0][x];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0, vector<int>(30));

    for (int i = 1; i <= n; ++i) {
        sort(ne[i].begin(), ne[i].end(), [&](int &u, int &v) {
            return d[u] > d[v];
        });
        ne[i].erase(unique(ne[i].begin(), ne[i].end()), ne[i].end());
        while (ne[i].size() && ne[i].back() == 0) {
            ne[i].pop_back();
        }
    }

    int q;
    cin >> q;

    auto getWeight = [&](int bit, int x, int y, int g) {
        return one[bit][x] + one[bit][y] - one[bit][g] - one[bit][f[0][g]];
    };

    auto getW = [&](int x, int y, int g) {
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            if (getWeight(i, x, y, g)) {
                ans += 1;
            }
        }
        return ans;
    };

    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        int g = lca(x, y);
        for (auto &z : ne[x]) {
            if (d[z] >= d[g]) {
                ans = max(ans, getW(x, z, z) + getW(z, y, g));
            } else {
                break;
            }
        }
        for (auto &z : ne[y]) {
            if (d[z] >= d[g]) {
                ans = max(ans, getW(y, z, z) + getW(z, x, g));
            } else {
                break;
            }
        }

        ans = max(ans, getW(x, g, g) + getW(y, g, g));

        cout << ans << ' ';
        // cout << ans << endl;
    }
    cout << '\n';
}

int main() {
    for (int i = 2; i < N; ++i) {
        _lg[i] = _lg[i / 2] + 1;
    }

    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}