#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

void solve() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for (auto& [l, r] : a) {
        cin >> l >> r;
    }

    auto check = [&](int k) {
        int L = 0, R = 0;

        for (auto [l, r] : a) {
            L = L - k;
            R = R + k;
            if (L > r || R < l) {
                return 0;
            } 
            L = max(L, l);
            R = min(R, r);
        }
        return 1;
    };

    int L = 0, R = 1e9;
    while (L < R) {
        int mid = L + R >> 1;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << R << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}