#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
LL a[N];
int d[1000][1000];

int get(int i, int j) {
    if (a[i] & a[j]) return 1;
    return 0x3f3f3f3f;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<LL>());
    while (n && a[n] == 0) --n;
    if (!n) return cout << -1 << endl, 0;

    for (int i = 0; i < 60; ++i) {
        int c = 0;
        for (int j = 1; j <= n; ++j) {
            c += a[j] >> i & 1;
        }
        if (c >= 3) {
            cout << 3 << endl;
            return 0;
        }
    }
    int ans = 0x3f3f3f3f;

    memset(d, 0x3f, sizeof(d));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] = get(i, j);
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i < k; ++i) {
            if (get(i, k) == 0x3f3f3f3f) continue;
            for (int j = i + 1; j < k; ++j) {
                ans = min(ans, d[i][j] + get(i, k) + get(k, j));
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    if (ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}