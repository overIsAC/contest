#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

LL n, s, t;

PLL calc(LL n, LL o) {
    if (n == 0) {
        return {0, 0};
    }
    LL len = 1LL << (n - 1), s = 1LL << (2LL * n - 2);
    int num = o / s;
    auto p = calc(n - 1, o % s);
    LL x = p.first, y = p.second;
    if (num == 0) {
        return {y, x};
    }
    if (num == 1) {
        return {x, y + len};
    }
    if (num == 2) {
        return {x + len, y + len};
    }
    return {2 * len - y - 1, len - x - 1};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s >> t;
        auto u = calc(n, s - 1), v = calc(n, t - 1);
        auto d = sqrtl((u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second)) * 10;
        cout << fixed << setprecision(0) << d << endl;
    }
    return 0;
}