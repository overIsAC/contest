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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> a, b, c, d;
        while (n--) {
            int x, y;
            cin >> x >> y;
            a[x] += 1;
            b[y] += 1;
            c[x - y] += 1;
            d[x + y] += 1;
        }
        LL ans = 0;
        for (auto &[x, y] : a) {
            ans += (LL)y * (y - 1) / 2;
        }
        for (auto &[x, y] : b) {
            ans += (LL)y * (y - 1) / 2;
        }
        for (auto &[x, y] : c) {
            ans += (LL)y * (y - 1) / 2;
        }
        for (auto &[x, y] : d) {
            ans += (LL)y * (y - 1) / 2;
        }
        cout << ans * 2 << endl;
    }
    return 0;
}