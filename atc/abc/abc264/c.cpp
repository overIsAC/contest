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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &i : a) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    int h, w;
    cin >> h >> w;
    vector<vector<int>> b(h, vector<int>(w));
    for (auto &i : b) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    auto ok = [&](int st1, int st2) -> bool {
        vector<int> u, v;
        for (int i = 0; i < n; ++i) {
            if (st1 >> i & 1) {
                u.push_back(i);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (st2 >> i & 1) {
                v.push_back(i);
            }
        }
        if (h != u.size() || w != v.size()) {
            return false;
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (b[i][j] != a[u[i]][v[j]]) {
                    return false;
                }
            }
        }
        return true;
    };
    for (int i = 1; i < 1 << n; ++i) {
        for (int j = 1; j < 1 << m; ++j) {
            if (ok(i, j)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}