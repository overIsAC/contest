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

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> next(n, n), prev(n, -1);
    for (int i = 0; i < n; ++i) {
        if (i) {
            prev[i] = prev[i - 1];
        }
        if (s[i] == '0') {
            prev[i] = i;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n) {
            next[i] = next[i + 1];
        }
        if (s[i] == '1') {
            next[i] = i;
        }
    }
    set<PII> st;
    int ans = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if (s[l] == '0') {
            l = next[l];
        }
        if (s[r] == '1') {
            r = prev[r];
        }
        // cout << "*** " << l + 1 << ' ' << r + 1 << endl;
        if (l > r) {
            ans = 1;
        } else {
            st.insert({l, r});
        }
    }
    ans += st.size();
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}