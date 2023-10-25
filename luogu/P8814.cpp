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
    LL n, d, e;
    cin >> n >> d >> e;
    LL m = n - e * d + 2;
    LL o = m * m - 4 * n;
    if (o < 0) {
        cout << "NO" << endl;
        return;
    }
    o = sqrtl(o);
    if (o * o != m * m - 4 * n) {
        cout << "NO" << endl;
        return;
    }
    if ((o + m) % 2) {
        cout << "NO" << endl;
        return;
    }
    LL p = (m - o) / 2, q = (m + o) / 2;
    if (p > q) {
        swap(p, q);
    }
    cout << p << ' ' << q << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}