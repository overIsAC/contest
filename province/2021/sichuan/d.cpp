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

void solve() {
    int br, bp, bs;
    int dr, dp, ds;
    cin >> br >> bp >> bs;
    cin >> dr >> dp >> ds;

    auto update = [&](int& u, int& v) {
        int t = min(u, v);
        u -= t;
        v -= t;
        return t;
    };

    LL ans = 0;

    ans += update(dr, bs);
    ans += update(dp, br);
    ans += update(ds, bp);

    update(dr, br);
    update(dp, bp);
    update(ds, bs);

    ans -= dr;
    ans -= dp;
    ans -= ds;
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}