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
const int N = 3 + 1e3;

int n, k, a[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    auto ok = [&](int v) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= v) {
                return 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int d = v - a[i];
            if (d > k) {
                continue;
            }
            for (int j = i + 1; j <= n; ++j) {
                if (a[j] >= v - (j - i)) {
                    return 1;
                }
                d += (v - (j - i)) - a[j];
                if (d > k) {
                    break;
                }
            }
        }
        return 0;
    };

    int l = 1, r = 2e8;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}