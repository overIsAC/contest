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
const int N = 3 + 2e5;

int n, m, l[N], r[N], q, p[N];
int pre[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> l[i] >> r[i];
        }
        cin >> q;
        for (int i = 1; i <= q; ++i) {
            cin >> p[i];
        }
        int L = 1, R = q;
        auto ok = [&](int o) {
            for (int i = 1; i <= n; ++i) {
                pre[i] = 0;
            }
            for (int i = 1; i <= o; ++i) {
                pre[p[i]] = 1;
            }
            for (int i = 1; i <= n; ++i) {
                pre[i] += pre[i - 1];
            }
            for (int i = 1; i <= m; ++i) {
                if ((pre[r[i]] - pre[l[i] - 1]) * 2 > r[i] - l[i] + 1) {
                    return 1;
                }
            }
            return 0;
        };
        while (L < R) {
            int mid = L + R >> 1;
            if (ok(mid)) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        if (!ok(R)) {
            R = -1;
        }
        cout << R << endl;
    }
    return 0;
}