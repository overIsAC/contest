#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 1e5;

int n, m, a[N];
int pre[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    double l = 0, r = 1e9;

    auto ok = [&](double v) -> bool {
        double minv = 1e9;
        for (int i = m; i <= n; ++i) {
            minv = min(minv, pre[i - m] - (i - m) * v);
            if (pre[i] - i * v >= minv) {
                return true;
            }
        }
        return false;
    };

    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int ans = 1000 * r;
    cout << ans << endl;

    return 0;
}