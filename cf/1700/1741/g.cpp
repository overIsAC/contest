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
const int N = 3 + 1e4;

int n, m;
vector<int> edge[N];
int f, h[N];
int k, p[111];
int st[N];
int vis[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
        st[i] = 0;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cin >> f;
    for (int i = 1; i <= f; ++i) {
        cin >> h[i];
        vis[i] = 0;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
        st[h[p[i]]] |= 1 << i;
        vis[p[i]] = 1;
    }
    vector d(n + 1, vector<int>(1 << k, n));
    vector v(n + 1, vector<int>(1 << k, 0));
    d[1][0] = 0;
    priority_queue<array<int, 3>> q;
    q.push({0, 1, 0});

    while (q.size()) {
        auto [_, x, i] = q.top();
        q.pop();
        if (v[x][i]) {
            continue;
        }
        v[x][i] = 1;
        for (auto &y : edge[x]) {
            if (d[y][i | st[y]] > d[x][i] + 1) {
                d[y][i | st[y]] = d[x][i] + 1;
                q.push({-d[y][i | st[y]], y, i | st[y]});
            }
        }
    }
    vector<int> dp(1 << k);
    dp[0] = 1;
    for (int i = 1; i <= f; ++i) {
        if (vis[i]) {
            continue;
        }
        int mn = n;
        for (auto &j : d[h[i]]) {
            mn = min(mn, j);
        }
        vector<int> temp(1 << k);
        for (int j = 0; j < 1 << k; ++j) {
            if (d[h[i]][j] == mn) {
                for (int q = 0; q < 1 << k; ++q) {
                    if (dp[q]) {
                        temp[q | j] = 1;
                    }
                }
            }
        }
        swap(dp, temp);
    }
    int ans = 0;
    for (int i = 0; i < 1 << k; ++i) {
        if (dp[i]) {
            int cnt = 0;
            for (int j = 0; j < k; ++j) {
                if (i >> j & 1) {
                    ++cnt;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << k - ans << endl;
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