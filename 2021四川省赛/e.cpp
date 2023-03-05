#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 1e5;

set<int> edge[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            edge[x].insert(y);
            edge[y].insert(x);
        }
        int ans = 0;
        int id = 2;
        bool ok = false;
        function<void(int)> dfs = [&](int x) {
            // cout << " dfs " << x << ' ' << id << ' ' << ans << endl;
            if (ok || id >= n + 1) {
                ok = true;
                return;
            }
            // cout << " dfs " << x << ' ' << id << ' ' << ans << ' ' << ok << endl;
            while (true) {
                if (ok) {
                    break;
                }
                if (edge[x].count(id)) {
                    // cout << x << ' ' << id << ' ' << "count" << endl;
                    ++id;
                    dfs(id - 1);
                    continue;
                }
                if (edge[x].upper_bound(id) != edge[x].end()) {
                    // cout << x << ' ' << id << ' ' << "upper" << endl;
                    ++id;
                    ++ans;
                    dfs(id - 1);
                    continue;
                }
                // cout << x << ' ' << id << endl;
                break;
            }
        };
        dfs(1);
        while (id <= n) {
            ++id;
            ++ans;
            dfs(id - 1);
        }
        // cout << " " << id << ' ' << ans << endl;
        cout << ans << endl;
    }
}
