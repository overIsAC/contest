#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

bool vis[1 << 17];

int main() {
    cout << ((4 & 7) + (2 & 6) + (1 & 5)) << endl;
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (n == 4 && k == 3) {
            cout << -1 << endl;
            continue;
        }
        if (k == n - 1) {
            
            continue;
        }
        for (int i = 0; i < n; ++i) {
            vis[i] = false;
        }
        vector<PII> ve;
        ve.push_back({n - 1, k});
        vis[n - 1] = vis[k] = true;
        bool ok = true;
        for (int i = n - 1; i >= 0; --i) {
            if (vis[i]) continue;
            if (vis[n - 1 ^ i]) {
                if (vis[0]) {
                    ok = false;
                    break;
                }
                vis[0] = vis[i] = true;
                ve.push_back({0, i});
            } else {
                ve.push_back({i, n - 1 ^ i});
                vis[i] = vis[n - 1 ^ i] = true;
            }
        }
        if (ok) {
            for (auto &i : ve) {
                cout << i.first << ' ' << i.second << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}