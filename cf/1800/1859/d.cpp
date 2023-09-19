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
const int N = 3 + 2e5;

PII e[N];
int n, q, t;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        e[i] = {a, d};
    }
    sort(e + 1, e + n + 1);

    int t = 1;
    for (int i = 2; i <= n; ++i) {
        if (e[t].second < e[i].second) {
            e[++t] = e[i];
        }
    }

    n = t;
    // for (int i = 1; i <= n; ++i) {
    //     cout << e[i].first << ' ' << e[i].second << endl;
    // }
    for (int i = n - 1; i >= 1; --i) {
        if (e[i].second >= e[i + 1].first) {
            e[i].second = max(e[i].second, e[i + 1].second);
        }
    }
    // cout << endl;
    // for (int i = 1; i <= n; ++i) {
    //     cout << e[i].first << ' ' << e[i].second << endl;
    // }

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int ans = x;
        int p = lower_bound(e + 1, e + n + 1, make_pair(x, 0)) - e;
        for (int i = -1; i <= 1; ++i) {
            int pp = i + p;
            if (1 <= pp && pp <= n && e[pp].first <= x && x <= e[pp].second) {
                ans = max(ans, e[pp].second);
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}