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
const int N = 3 + 5e5;

int fa[N], sz[N];
int n, m;

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int k, u = 0, v;
        cin >> k;
        while (k--) {
            cin >> v;
            if (!u) {
                u = v;
                continue;
            }
            u = find(u);
            v = find(v);
            if (u == v) {
                continue;
            }
            sz[u] += sz[v];
            fa[v] = u;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << sz[find(i)] << ' ';
    }
    return 0;
}