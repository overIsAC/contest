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
const int N = 3 + 1e5;

int n, m, a[N];
int b[N], t;
int pre[N], suf[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        map<int, int> mp;
        int u = 0, v = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == -1) {
                ++u;
            } else if (a[i] == -2) {
                ++v;
            } else {
                ++mp[a[i]];
            }
        }
        t = 0;
        for (auto &[i, j] : mp) {
            b[++t] = i;
        }
        // cout << t << endl;
        for (int i = 1; i <= t; ++i) {
            pre[i] = pre[i - 1] + b[i] - b[i - 1] - 1;
        }
        b[t + 1] = m + 1;
        suf[t + 1] = 0;
        for (int i = t; i >= 1; --i) {
            suf[i] = suf[i + 1] + b[i + 1] - b[i] - 1;
        }
        int ans = max({min(t, u), min(t, v), t});
        ans = max(ans, min(m - t, max(u, v)) + t);

        for (int i = 1; i <= t; ++i) {
            // cout << i << ' ' << pre[i] << ' ' << suf[i] << endl;
            ans = max(ans, t + min(pre[i], u) + min(suf[i], v));
        }
        cout << ans << endl;
    }
    return 0;
}