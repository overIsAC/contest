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
    LL x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<LL> a, b, c;
    for (LL i = 1;; i *= x) {
        a.push_back(i);
        if (i > 1e18 / x) {
            break;
        }
    }
    for (LL i = 1;; i *= y) {
        b.push_back(i);
        if (i > 1e18 / y) {
            break;
        }
    }
    for (auto &i : a) {
        for (auto &j : b) {
            if (l <= i + j && i + j <= r) {
                c.push_back(i + j);
            }
        }
    }
    sort(c.begin(), c.end());
    if (c.empty()) {
        cout << r - l + 1 << endl;
        return 0;
    }
    LL ans = max(c[0] - l, r - c.back());
    for (int i = 1; i < c.size(); ++i) {
        ans = max(ans, c[i] - c[i - 1] - 1);
    }
    cout << ans << endl;
    return 0;
}