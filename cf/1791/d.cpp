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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        set<int> st;
        vector<int> pre;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            st.insert(s[i]);
            pre.push_back(st.size());
        }
        st.clear();
        int ans = 0;
        for (int i = n - 1; i > 0; --i) {
            st.insert(s[i]);
            ans = max<int>(ans, pre[i - 1] + st.size());
        }
        cout << ans << endl;
    }
    return 0;
}