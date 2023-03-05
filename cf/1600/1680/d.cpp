#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 3000;

int a[N], n, k;

int main() {
    cin >> n >> k;
    int z = 0;
    LL tot = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tot += a[i];
        z += !a[i];
    }
    if (tot > (LL)z * k) {
        cout << -1 << endl;
        return 0;
    }
    if (tot == 0) {
        LL l = 0, r = 0, now = 0;
        for (int i = 1; i <= n; ++i) {
            now += a[i];
            l = min(l, now);
            r = max(r, now);
        }
        cout << r - l + 1 + (LL)z / 2 * k << endl;
        return 0;
    }
    LL l = 0, r = 0, now = 0;
    for (int i = 1; i <= n; ++i) {
        now += a[i];
        l = min(l, now);
        r = max(r, now);
    }
    LL q = abs(now) / k;
    now %= k;
    z -= q;
    cout << l << ' ' << r << endl;
    cout << now << endl;
    if (z & 1) {
        --z;
        cout << r - l + 1 + (l && r ? abs(now) : 0) + z / 2 * k << endl;
    } else {
        --z;
        cout << r - l + 1 + (l && r ? abs(now) : 0) + z / 2 * k + k - now
             << endl;
    }
    return 0;
}