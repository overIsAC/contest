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
    vector<PII> ans;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    set<int> st;
    vector<int> ok(n);
    for (int i = 0; i < n; ++i) {
        if (st.count(a[i])) {
            break;
        }
        st.insert(a[i]);
        if (*st.begin() == 1 && *st.rbegin() == i + 1 && st.size() == i + 1) {
            ok[i] = 1;
        }
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (st.count(a[i])) {
            break;
        }
        st.insert(a[i]);
        if (i == 0 || ok[i - 1]) {
            if (*st.begin() == 1 && *st.rbegin() == n - i && st.size() == n - i) {
                ans.push_back({i, n - i});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}