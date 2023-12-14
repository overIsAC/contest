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
const int N = 3 + 1e6;

int n, h[N], c[N];
LL m;

int ok(int lower) {
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] <= lower) {
            continue;
        }
        sum += h[i] - max(lower, c[i]);
        if (sum > m) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i] >> c[i];
    }
    int l = 0, r = 1e6;
    while (l < r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    auto calc = [&](int l, int r) {
        if (l >= r) {
            return 0LL;
        }
        int x = r - l, h = r;
        return (LL)x * (h + h - x);
    };

    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (max(c[i], r) >= h[i]) {
            continue;
        }
        ans += calc(max(c[i], r), h[i]);
        m -= h[i] - max(c[i], r);
        h[i] = max(c[i], r);
    }

    for (int i = 1; i <= n && m; ++i) {
        if (c[i] >= h[i]) {
            continue;
        }
        ans += h[i] + h[i] - 1;
        --m;
    }

    cout << ans << endl;
    return 0;
}


