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

int n, m, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        n = unique(a + 1, a + n + 1) - a - 1;
        map<int, int> mp;
        int cnt = 0;
        auto f = [&](int p, int v) {
            if (p <= m) {
                if (v == 1) {
                    if (!mp[p]++) {
                        ++cnt;
                    }
                } else {
                    if (!--mp[p]) {
                        --cnt;
                    }
                }
            }
        };
        auto dec = [&](int p, int v) {
            for (int i = 1; i * i <= p; ++i) {
                if (p % i == 0) {
                    f(i, v);
                    if (i * i != p) {
                        f(p / i, v);
                    }
                }
            }
        };
        int ans = 1e9;
        for (int i = 1, j = 1; i <= n; ++i) {
            dec(a[i], 1);
            while (cnt == m) {
                ans = min(ans, a[i] - a[j]);
                dec(a[j], -1);
                ++j;
            }
        }
        if (ans == 1e9) {
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}