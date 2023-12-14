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
const int N = 3 + 2e5;

char s[N];
int n, q;
int prex[N], prey[N];
int sufx[N], sufy[N];
map<PII, int> pre, suf;
map<PII, vector<int>> mp;

void solve() {
    cin >> n >> q;
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        prex[i] = prex[i - 1];
        prey[i] = prey[i - 1];
        if (s[i] == 'U') {
            ++prey[i];
        }
        if (s[i] == 'D') {
            --prey[i];
        }
        if (s[i] == 'L') {
            --prex[i];
        }
        if (s[i] == 'R') {
            ++prex[i];
        }
    }
    for (int i = n; i >= 1; --i) {
        sufx[i] = sufx[i + 1];
        sufy[i] = sufy[i + 1];
        if (s[i] == 'U') {
            ++sufy[i];
        }
        if (s[i] == 'D') {
            --sufy[i];
        }
        if (s[i] == 'L') {
            --sufx[i];
        }
        if (s[i] == 'R') {
            ++sufx[i];
        }
        mp[{sufx[i], sufy[i]}].push_back(i);
    }
    for (auto& [u, v] : mp) {
        reverse(v.begin(), v.end());
    }

    for (int i = 0; i <= n; ++i) {
        if (!pre.count({prex[i], prey[i]})) {
            pre[{prex[i], prey[i]}] = i;
        }
        suf[{prex[i], prey[i]}] = i;
    }
    // for (auto [x, y] : mp) {
    //     cout << x.first << ' ' << x.second << endl;
    // }

    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if (x == 0 && y == 0) {
            cout << "YES" << endl;
            continue;
        }
        if (pre.count({x, y}) && pre[{x, y}] < l) {
            cout << "YES" << endl;
            continue;
        }
        if (suf.count({x, y}) && suf[{x, y}] > r) {
            cout << "YES" << endl;
            continue;
        }
        x -= prex[l - 1];
        y -= prey[l - 1];
        x += sufx[r + 1];
        y += sufy[r + 1];
        if (!mp.count({x, y})) {
            cout << "NO" << endl;
            continue;
        }
        auto& v = mp[{x, y}];
        auto p = lower_bound(v.begin(), v.end(), l);
        if (p != v.end() && *p <= r) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}