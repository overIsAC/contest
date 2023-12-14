#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

void solve() {
    int n, m, r;
    cin >> n >> m;
    vector<vector<set<int>>> d(n + 1, vector<set<int>>(m + 1));
    vector<vector<int>> banx(n + 1), bany(m + 1);
    cin >> r;
    for (int i = 1; i <= r; ++i) {
        int op, t, p;
        cin >> t >> op >> p;
        if (op == 1) {
            banx[p].push_back(t);
        } else {
            bany[p].push_back(t);
        }
    }

    auto ins = [&](int x, int y, int v) {
        auto& st = d[x][y];
        if (st.size() && v - *st.begin() > r) {
            return 0;
        }
        for (auto& t : banx[x]) {
            if (v == t) {
                return 0;
            }
        }
        for (auto& t : bany[y]) {
            if (v == t) {
                return 0;
            }
        }

        st.insert(v);
        return 1;
    };

    for (int i = 0; i <= r; ++i) {
        if (!ins(0, 0, i)) {
            break;
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int mx = 0;
            for (auto& t : d[i][j]) {
                if (t <= mx) {
                    continue;
                }
                for (int z = 1; z <= r; ++z) {
                    if (!ins(i, j, t + z)) {
                        break;
                    }
                    mx = max(mx, t + z);
                }
            }
            for (auto& t : d[i][j]) {
                if (i < n) {
                    ins(i + 1, j, t + 1);
                }
                if (j < m) {
                    ins(i, j + 1, t + 1);
                }
            }
        }
    }
    auto& st = d[n][m];
    if (st.empty()) {
        cout << -1 << endl;
    } else {
        cout << *st.begin() << endl;
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