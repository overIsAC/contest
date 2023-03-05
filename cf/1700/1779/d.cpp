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

int n, m, a[N], b[N], c[N];
map<int, vector<int>, greater<int>> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        cin >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> c[i];
        }
        map<int, int> cnt;
        for (int i = 1; i <= m; ++i) {
            ++cnt[c[i]];
        }
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            mp[b[i]].push_back(i);
        }
        set<int> st;
        bool ok = true;
        for (auto &i : mp) {
            auto &ve = i.second;
            for (int j = 0; j < ve.size(); ++j) {
                if (a[ve[j]] == b[ve[j]]) {
                    st.insert(ve[j]);
                    continue;
                }
                if (!cnt[i.first]) {
                    ok = false;
                    break;
                }
                --cnt[i.first];
                auto p = st.lower_bound(ve[j]);
                if (p == st.end()) {
                    while (j < ve.size()) {
                        st.insert(ve[j]);
                        a[ve[j]] = min(a[ve[j]], i.first);
                        ++j;
                    }
                    break;
                }
                int k = j;
                st.insert(ve[j]);
                a[ve[j]] = min(a[ve[j]], i.first);

                while (k + 1 < ve.size() && ve[k + 1] < *p) {
                    st.insert(ve[k + 1]);
                    a[ve[k + 1]] = min(a[ve[k + 1]], i.first);
                    ++k;
                }
            }
        }
        if (ok) {
            for (int i = 1; i <= n; ++i) {
                if (a[i] != b[i]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}