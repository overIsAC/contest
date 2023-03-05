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

int n, k;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s >> t;
        set<char> st(s.begin(), s.end());
        vector<char> ve(st.begin(), st.end());
        const int m = ve.size();
        int up = 1 << m;
        LL ans = 0;
        for (int i = 0; i < up; ++i) {
            int cnt = 0;
            st.clear();
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    ++cnt;
                    st.insert(ve[j]);
                }
            }
            if (cnt > k) {
                continue;
            }
            LL temp = 0;
            for (int j = 0; j < n; ++j) {
                if (s[j] != t[j] && !st.count(s[j])) {
                    continue;
                }
                int q = j;
                while (q + 1 < n && (s[q + 1] == t[q + 1] || st.count(s[q + 1]))) {
                    ++q;
                }
                temp += (LL)(q - j + 1) * (q - j) / 2 + (q - j + 1);
                j = q;
            }
            ans = max(temp, ans);
        }
        cout << ans << endl;
    }
    return 0;
}