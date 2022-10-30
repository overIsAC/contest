#include <bits/stdc++.h>
using namespace std;
#define int long long
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

LL n, c, q, l, r;
PII b[N], d[N];
char s[N];

void solve() {
    cin >> n >> c >> q;
    cin >> s + 1;
    b[0] = {1, n};
    LL now_n = n;
    for (int i = 1; i <= c; ++i) {
        cin >> l >> r;
        d[i] = {l, r};
        b[i] = {now_n + 1, now_n + r - l + 1};
        now_n += r - l + 1;
    }
    while (q--) {
        LL k;
        cin >> k;
        int p = c;
        while (k > n) {
            if (b[p].first <= k && k <= b[p].second) {
                k = k - b[p].first + d[p].first;
            }
            p -= 1;
        }
        cout << s[k] << endl;
    }
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}