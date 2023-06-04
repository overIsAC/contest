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

const int mod = 7 + 1e4;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];
vector<int> edge[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int mx = 0, ans = 0;
    for (int x = 1; x <= n; ++x) {
        int cnt = 0, t = 0;
        for (auto &y : edge[x]) {
            ans += a[y] * cnt * 2;
            ans %= mod;
            mx = max(mx, t * a[y]);
            t = max(t, a[y]);
            cnt += a[y];
            cnt %= mod;
        }
    }
    cout << mx << ' ' << ans << endl;
    return 0;
}