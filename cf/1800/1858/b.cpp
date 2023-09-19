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

int n, m, d, a[N];
int suf[N];

void solve() {
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    if (m == 1) {
        cout << 1 + (n - 1) / d << ' ' << 1 << endl;
        return;
    }
    suf[m] = 1 + (n - a[m]) / d;
    for (int i = m - 1; i >= 1; --i) {
        suf[i] = suf[i + 1];
        suf[i] += 1 + (a[i + 1] - a[i] - 1) / d;
    }
    int ans = 1 + (a[2] - 2) / d + suf[2];
    db(1 + (a[2] - 2) / d + suf[2]);

    int pre = 1 + (a[1] - 2) / d;
    if (a[1] != 1) {
        ++pre;
    }
    for (int i = 2; i < m; ++i) {
        db(pre + suf[i + 1] + (a[i + 1] - a[i - 1] - 1) / d);
        ans = min(ans, pre + suf[i + 1] + (a[i + 1] - a[i - 1] - 1) / d);
        pre += 1 + (a[i] - a[i - 1] - 1) / d;
    }
    ans = min(ans, pre + (n - a[m - 1]) / d);

    int cnt = 0;
    if (1 + (a[2] - 2) / d + suf[2] == ans) {
        ++cnt;
    }
    db(ans);

    pre = 1 + (a[1] - 2) / d;
    if (a[1] != 1) {
        ++pre;
    }

    for (int i = 2; i < m; ++i) {
        if (ans == pre + suf[i + 1] + (a[i + 1] - a[i - 1] - 1) / d) {
            ++cnt;
        }
        pre += 1 + (a[i] - a[i - 1] - 1) / d;
    }
    if (ans == pre + (n - a[m - 1]) / d) {
        ++cnt;
    }

    cout << ans << ' ' << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}