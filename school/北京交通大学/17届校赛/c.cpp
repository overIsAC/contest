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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y, hp;
        cin >> n >> m >> x >> y >> hp;
        LL ans = LLONG_MAX;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if ((LL)i * (j + 1) >= hp) {
                    LL cost = (LL)i * x + (LL)j * y;
                    if (cost < ans) {
                        ans = cost;
                    } else {
                        break;
                    }
                }
            }
        }
        if (ans == LLONG_MAX) {
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}