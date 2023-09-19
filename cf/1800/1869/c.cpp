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

int mex(vector<vector<int>> a) {
    set<int> st;
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < m; ++i) {
        set<int> s;
        for (int j = 0; j < n; ++j) {
            s.insert(a[j][i]);
        }
        int cnt = 0;
        while (s.count(cnt)) {
            ++cnt;
        }
        st.insert(cnt);
    }
    int ans = 0;
    while (st.count(ans)) {
        ++ans;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector ans(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        ans[i][0] = m - 1;
    }
    for (int i = 0; i < min(n, m); ++i) {
        for (int j = i + 1; j < m; ++j) {
            ans[i][j] = j - i - 1;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[j][i] == -1) {
                ans[j][i] = m - i - 1;
            }
        }
        if (m - i - 1 == ans[0][i] + 1) {
            for (int j = 0; j < n; ++j) {
                if (ans[j][i] == m - i - 1) {
                    swap(ans[j][0], ans[j][i]);
                }
            }
        }
    }
    cout << mex(ans) << endl;

    for (auto &i : ans) {
        for (auto &j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
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