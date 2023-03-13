#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, m;
int u, v;
string s;

int fa[N];
int sz[N];
int vis[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n * 2; ++i) {
        fa[i] = i;
        sz[i] = 0;
        vis[i] = 0;
    }
    bool flag = true;
    while (m--) {
        cin >> u >> v >> s;
        int type = s == "crewmate" ? 1 : 0;
        if (type) {
            if (find(u) == find(v + n) || find(u + n) == find(v)) {
                flag = false;
            }
            fa[find(u)] = find(v);
            fa[find(u + n)] = find(v + n);
        } else {
            if (find(u) == find(v) || find(u + n) == find(v + n)) {
                flag = false;
            }
            fa[find(u)] = find(v + n);
            fa[find(u + n)] = find(v);
        }
    }
    if (!flag) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        ++sz[find(i)];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[find(i)] || vis[find(i + n)]) {
            continue;
        }
        vis[find(i)] = vis[find(i + n)] = 1;
        ans += max(sz[find(i)], sz[find(i + n)]);
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