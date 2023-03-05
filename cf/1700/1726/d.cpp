#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 12 + 2e5;

int fa[N];
int n, m;
int ans[N];
int u[N], v[N];
set<int> edge[N];

int find(int p) { return p == fa[p] ? p : fa[p] = find(fa[p]); }

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    fa[u] = v;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (m <= n + 1) {
            int u, v;
            for (int i = 1; i <= n; ++i) {
                fa[i] = i;
            }
            for (int i = 1; i <= m; ++i) {
                cin >> u >> v;
                if (find(u) == find(v)) {
                    cout << 0;
                } else {
                    cout << 1;
                }
                merge(u, v);
            }
            cout << endl;
        } else {
            for (int i = 1; i <= n; ++i) {
                edge[i].clear();
                ans[i] = 0;
            }
            for (int i = 1; i <= m; ++i) {
                cin >> u[i] >> v[i];
                edge[u[i]].insert(v[i]);
                edge[v[i]].insert(u[i]);
            }
            bool ok = false;
            for (int i = 1; i <= m; ++i) {
                for (auto &j : edge[u[i]]) {
                    if (j == v[i]) continue;
                    for (auto &k : edge[v[i]]) {
                        if (k == u[i]) continue;
                        if (k == j) continue;
                        ok = true;
                        ans[u[i]] = 1;
                        ans[v[i]] = 1;
                        ans[j] = 1;
                        ans[k] = 1;
                        break;
                    }
                    if (ok) {
                        break;
                    }
                }
                if (ok) {
                    break;
                }
            }

            for (int i = 1; i <= m; ++i) {
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}