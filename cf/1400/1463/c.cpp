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

int n, t[N], x[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> t[i] >> x[i];
        }
        int p = 0, sp = 0, ed = 0;
        int ans = 0;
        int last = -2e9;
        auto in = [&](int l, int r, int v) {
            if (l > r) {
                swap(l, r);
            }
            return l <= v && v <= r;
        };
        for (int i = 1; i <= n; ++i) {
            int dt = min(abs(ed - p), t[i] - t[i - 1]);
            if (in(p, p + sp * dt, last)) {
                ++ans;
            }
            p += sp * dt;
            if (p == ed) {
                sp = 0;
            }
            if (sp == 0) {
                if (p != x[i]) {
                    ed = x[i];
                    if (p < x[i]) {
                        sp = 1;
                    } else {
                        sp = -1;
                    }
                }
            }
            last = x[i];
            // cout << p << ' ' << sp << ' ' << ans << endl;
        }
        // cout << p << ' ' << p + sp * abs(ed - p) << endl;
        if (in(p, p + sp * abs(ed - p), last)) {
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}