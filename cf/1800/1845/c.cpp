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
        string s;
        int m;
        string l, r;
        cin >> s;
        cin >> m;
        cin >> l >> r;
        vector<set<int>> u(m);
        for (auto &i : s) {
            vector<set<int>> v(m);
            if (l[0] <= i && i <= r[0]) {
                v[0].insert(i);
            }
            for (int j = 1; j < m; ++j) {
                if (u[j - 1].size() == r[j - 1] - l[j - 1] + 1 && l[j] <= i && i <= r[j]) {
                    v[j].insert(i);
                }
            }
            for (int j = 0; j < m; ++j) {
                u[j].insert(v[j].begin(), v[j].end());
            }
        }
        cout << ((u.back().size() < r.back() - l.back() + 1 ? "YES" : "NO")) << endl;
    }
    return 0;
}