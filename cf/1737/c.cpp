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

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x[3], y[3], ex, ey;
        int n;
        cin >> n;
        for (int i = 0; i < 3; ++i) {
            cin >> x[i] >> y[i];
        }
        cin >> ex >> ey;

        vector<vector<PII>> ve;

        ve.push_back({{1, 1}, {1, 2}, {2, 1}});
        ve.push_back({{n, n}, {n - 1, n}, {n, n - 1}});
        ve.push_back({{1, n}, {2, n}, {1, n - 1}});
        ve.push_back({{n, 1}, {n, 2}, {n - 1, 1}});

        for (auto &i : ve) {
            sort(i.begin(), i.end());
        }
        auto check = [&]() {
            vector<PII> a = {{x[0], y[0]}, {x[1], y[1]}, {x[2], y[2]}};
            sort(a.begin(), a.end());
            for (auto &i : ve) {
                if (i == a) {
                    return true;
                }
            }
            return false;
        };

        bool ok = false;
        if (check()) {
            for (int i = 0; i < 3; ++i) {
                for (int j = i + 1; j < 3; ++j) {
                    if (x[i] == x[j] && x[i] == ex) {
                        ok = true;
                    }
                    if (y[i] == y[j] && y[i] == ey) {
                        ok = true;
                    }
                }
            }
        } else {
            for (int i = 0; i < 3; ++i) {
                for (int j = i + 1; j < 3; ++j) {
                    if (x[i] == x[j] && (x[i] - ex) % 2 == 0) {
                        ok = true;
                    }
                    if (y[i] == y[j] && (y[i] - ey) % 2 == 0) {
                        ok = true;
                    }
                }
            }
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}