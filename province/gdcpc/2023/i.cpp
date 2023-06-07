#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto &i : a) {
            for (auto &j : i) {
                cin >> j;
            }
        }
        vector<PII> b(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                b[a[i][j]] = {i, j};
            }
        }
        set<PII> st;
        st.insert({-1, -1});
        st.insert({n, m});
        int ans = 0;
        for (int i = 0; i < n * m; ++i) {
            auto R = st.lower_bound(b[i]);
            auto L = R;
            --L;
            if (L->first <= b[i].first && b[i].first <= R->first && L->second <= b[i].second && b[i].second <= R->second) {
                ++ans;
            } else {
                break;
            }
            st.insert(b[i]);
        }
        cout << ans << endl;
    }

    return 0;
}