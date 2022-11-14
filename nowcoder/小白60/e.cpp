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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

vector<int> edge[N];
int n, a[N];
int f[N * 5];

int fa[N], sz[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int main() {
    for (int i = 2; i < N * 5; ++i) {
        if (!f[i]) {
            for (int j = i; j < N * 5; j += i) {
                f[j] += 1;
            }
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        if (f[__gcd(a[u], a[v])] <= 1) {
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
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, sz[find(i)]);
    }
    cout << ans << endl;
    return 0;
}