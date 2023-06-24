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

int n, m;
vector<PII> edge[N];
int vis[N];
int r[N];

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    memset(r, 0x3f, sizeof(r));
    vis[n] = 1;
    for (auto &[y, w] : edge[n]) {
        r[y] = min(r[y], w);
    }

    vector<pair<string, int>> ans;
    while (!vis[1]) {
        int d = INT_MAX;
        for (int x = 1; x <= n; ++x) {
            if (vis[x]) {
                continue;
            }
            d = min(d, r[x]);
        }
        if (d >= 0x3f3f3f3f) {
            cout << "inf" << endl;
            return 0;
        }
        string s;
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) {
                s += '0';
            } else {
                s += '1';
            }
        }
        if (d) {
            ans.push_back({s, d});
        }
        set<int> st;
        for (int x = 1; x <= n; ++x) {
            if (vis[x]) {
                continue;
            }
            if (r[x] >= 0x3f3f3f3f) {
                continue;
            }
            r[x] -= d;
            if (!r[x]) {
                st.insert(x);
                vis[x] = 1;
            }
        }
        for (auto &x : st) {
            vis[x] = 1;
            for (auto &[y, w] : edge[x]) {
                r[y] = min(r[y], w);
            }
        }
    }
    while (ans.size() > n * (n - 1) / 2) {
        ans.pop_back();
    }
    LL sum = 0;
    sort(ans.begin(), ans.end(), [&](pair<string, int> &u, pair<string, int> &v) {
        return u.second > v.second;
    });
    for (auto &[x, y] : ans) {
        sum += y;
    }
    cout << sum << ' ' << ans.size() << endl;
    for (auto &[x, y] : ans) {
        cout << x << ' ' << y << endl;
    }
    return 0;
}

/*
3 3
1 2 111
2 3 234
1 3 345

*/