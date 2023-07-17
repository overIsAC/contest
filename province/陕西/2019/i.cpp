#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
const int N = 3 + 1e5;

vector<pair<int, char>> edge[N];
int vis[N];
int n;
vector<int> o;

void dfs(int x, int fa) {
    vis[x] = 1;
    for (auto [y, c] : edge[x]) {
        if (y == fa) {
            continue;
        }
        if (y == o[0] || y == o[1]) {
            continue;
        }
        dfs(y, x);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
        vis[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        edge[u].push_back({v, c});
        edge[v].push_back({u, c});
    }
    for (int i = 1; i <= n; ++i) {
        if (edge[i].size() > 27) {
            cout << 0 << endl;
            return;
        }
        int cnt[26] = {};
        for (auto [x, y] : edge[i]) {
            ++cnt[y - 'a'];
        }
        int t = 0;
        for (auto &j : cnt) {
            if (j >= 3) {
                cout << 0 << endl;
                return;
            }
            if (j == 2) {
                ++t;
            }
        }
        if (t >= 2) {
            cout << 0 << endl;
            return;
        }
        if (t == 1) {
            int p = -1;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] == 2) {
                    p = j;
                    break;
                }
            }
            o.clear();
            for (auto [x, y] : edge[i]) {
                if (y - 'a' == p) {
                    o.push_back(x);
                }
            }
            dfs(i, 0);
        }
    }
    cout << n - accumulate(vis + 1, vis + n + 1, 0) << endl;
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