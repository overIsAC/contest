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

int n, a[N], x[N], q;

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> x[i];
    }
    vector<vector<int>> ne(q + 3);
    ne[q + 1] = vector<int>(31, q + 1);
    for (int i = q; i >= 1; --i) {
        ne[i] = ne[i + 1];
        ne[i][x[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int v = a[i], p = 1;
        while (p <= q && v % 2 == 0) {
            int idx = q + 1;
            for (int j = 1; j <= 30; ++j) {
                idx = min(ne[p][j], idx);
                if (v >> j & 1) {
                    break;
                }
            }
            if (idx == q + 1) {
                break;
            }
            v |= 1 << x[idx] - 1;
            p = idx + 1;
        }
        cout << v << ' ';
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}