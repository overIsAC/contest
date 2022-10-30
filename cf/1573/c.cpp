#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
vector<int> edge[N];
int ind[N];
int b[N], t;
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            ind[i] = 0;
            edge[i].clear();
        }
        set<int> q;
        for (int i = 1; i <= n; ++i) {
            cin >> ind[i];
            for (int j = 1; j <= ind[i]; ++j) {
                int u, v = i;
                cin >> u;
                edge[u].push_back(v);
            }
            if (!ind[i]) q.insert(i);
        }
        t = 0;
        int ans = 1, x = 0;
        while (q.size()) {
            auto p = q.upper_bound(x);
            if (p == q.end()) {
                p = q.begin();
                ++ans;
            }
            x = *p;
            q.erase(p);
            ++t;
            for (auto &y : edge[x]) {
                if (!--ind[y]) {
                    q.insert(y);
                }
            }
        }
        if (t < n) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}