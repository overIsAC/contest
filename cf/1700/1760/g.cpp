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

vector<PII> edge[N];
int n, a, b;
int d[N];
int ok;
set<int> s1, s2;

void dfs(int x, int fa) {
    for (auto &e : edge[x]) {
        int y = e.first, w = e.second;
        if (y == fa) {
            continue;
        }
        d[y] = d[x] ^ w;
        dfs(y, x);
    }
}

void dfs2(int x, int fa, int z, set<int> &s) {
    for (auto &e : edge[x]) {
        int y = e.first, w = e.second;
        if (y == fa || y == z) {
            continue;
        }
        s.insert(d[y]);
        dfs2(y, x, z, s);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            edge[u].push_back({v, w});
            edge[v].push_back({u, w});
        }
        dfs(1, 0);
        ok = 0;
        if (d[a] == d[b]) {
            ok = 1;
        }
        s1.clear();
        s2.clear();
        dfs2(a, 0, b, s1);
        dfs2(b, 0, 0, s2);
        s1.insert(d[a]);
        for (auto &i : s1) {
            if (s2.count(d[a] ^ d[b] ^ i)) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}