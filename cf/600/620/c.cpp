#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e5;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<PII> ans;
    int t = 0;
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        if (!st.size()) {
            t = i;
            st.insert(a[i]);
        } else {
            if (st.count(a[i])) {
                ans.push_back({t, i});
                st.clear();
            } else {
                st.insert(a[i]);
            }
        }
    }

    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    ans.back().second = n;
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}