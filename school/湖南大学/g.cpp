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
#define int LL
// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e6;

int n, m, k;
int d[N];
int vis[N];

struct Node {
    int l, r, x;
    bool operator<(const Node& other) const {
        return l < other.l;
    }
} a[N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].x;
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; ++i) {
        auto [l, r, x] = a[i];
        d[r] = d[l - 1] ^ x;
    }
    for (int i = 1; i <= m; ++i) {
        auto [l, r, x] = a[i];
        vis[r] = 1;
        if (d[r] != (d[l - 1] ^ x)) {
            cout << 0 << endl;
            return 0;
        }
    }
    LL ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        for (int j = 0; j < k; ++j) {
            ans = ans * 2 % mod;
        }
    }
    cout << ans << endl;
    return 0;
}