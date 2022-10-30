#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#define endl '\n'

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m, a[N];
int q;
int sx, sy, ex, ey, k;

int f[N][20];
int Lg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    Lg[0] = -1;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        a[i] = n - a[i];
        f[i][0] = a[i];
        Lg[i] = Lg[i / 2] + 1;
    }
    for (int j = 1; j < 20; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }

    auto get = [&](int l, int r) {
        if (l > r) swap(l, r);
        int t = Lg[r - l + 1];
        return min(f[l][t], f[r - (1 << t) + 1][t]);
    };
    cin >> q;
    while (q--) {
        cin >> sx >> sy >> ex >> ey >> k;
        sx = n - sx + 1;
        ex = n - ex + 1;
        sx %= k;
        ex %= k;
        if (!sx) sx += k;
        if (!ex) ex += k;
        int mn = get(sy, ey);
        if (sx != ex || (ey - sy) % k) {
            cout << "NO" << endl;
            continue;
        }
        if (mn < sx) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}