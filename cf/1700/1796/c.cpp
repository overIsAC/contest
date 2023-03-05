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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e6;

int l, r;

int bin(int x) {
    int ans = 0;
    do {
        ans += 1;
        x /= 2;
    } while (x);
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> l >> r;
        if (l == r) {
            cout << "1 1" << endl;
            continue;
        }
        int step = bin(r / l);
        if (step == 1) {
            cout << 1 << ' ' << r - l + 1 << endl;
            continue;
        }
        int v = 1;
        for (int i = 1; i + 1 < step; ++i) {
            v *= 2;
        }
        LL ans = r / (v * 2) - l + 1;
        db(ans);
        if (l <= r / (v * 3)) {
            ans += (LL)(r / (v * 3) - l + 1) * (step - 1) % mod;
        }
        ans %= mod;
        cout << step << ' ' << ans << endl;
    }
    return 0;
}