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
const int N = 3 + 5e3;

void solve() {
    int n, a;
    cin >> n;
    int u = 1e9, v = 1e9, ans = 0;
    while (n--) {
        cin >> a;
        if (u < v) {
            swap(u, v);
        }
        if (a <= v) {
            v = a;
        } else if (a <= u) {
            u = a;
        } else {
            v = a;
            ++ans;
        }
    }
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