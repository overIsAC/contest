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

int n, a[N];
int pre[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;
        int L = l, R = n;
        while (L < R) {
            int mid = L + R + 1 >> 1;
            if (pre[mid] - pre[l - 1] <= u) {
                L = mid;
            } else {
                R = mid - 1;
            }
        }
        db(R);
        auto calc = [&](LL a, LL b) {
            return (a + b) * (b - a + 1) / 2;
        };
        auto calc2 = [&](int r) {
            return calc(u - (pre[r] - pre[l - 1] - 1), u);
        };
        if (R + 1 <= n) {
            if (calc2(R) >= calc2(R + 1)) {
                cout << R << ' ';
            } else {
                cout << R + 1 << ' ';
            }
        } else {
            cout << R << ' ';
        }
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