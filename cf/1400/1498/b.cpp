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
    int n, w;
    cin >> n >> w;
    multiset<int> st;
    while (st.size() < n) {
        int a;
        cin >> a;
        st.insert(a);
    }
    int ans = 0;
    while (st.size()) {
        int x = *st.rbegin();
        st.erase(--st.end());
        ++ans;
        while (true) {
            auto p = st.upper_bound(w - x);
            if (p == st.begin()) {
                break;
            }
            --p;
            x += *p;
            st.erase(p);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}