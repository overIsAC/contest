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
    // int n, m;
    // cin >> n >> m;
    // cout << n << ' ' ;
    // for (int i = m; i >= 1; --i) {
    //     cout << (n %= i) << ' ';
    // }
    // cout << endl;
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 3) {
        cout << 0 << endl;
        return;
    }
    int a = 0, b = 0, c = 0;
    a = 1;
    b = min(n - 1, m);
    b += m / n;
    c = m - b - a + 1;
    // cout << a << ' ' << b << ' ' << c << endl;
    if (k == 1) {
        cout << a << endl;
        return;
    }
    if (k == 2) {
        cout << b << endl;
        return;
    }
    cout << c << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}