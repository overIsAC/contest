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

int n;

int calc(int x, int y) {
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        if (i == y) {
            continue;
        }
        st.insert(i);
    }
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        if (i == x) {
            continue;
        }
        auto p = st.lower_bound(x * y / i);
        if (p == st.end() || *p * i > x * y) {
            if (p != st.begin()) {
                --p;
            }
        }
        if (p == st.end() || *p * i > x * y) {
            return 0;
        }
        ans += *p * i;
        st.erase(p);
    }
    return ans;
}

void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = max(ans, calc(i, j));
        }
    }
    cout << ans << endl;
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