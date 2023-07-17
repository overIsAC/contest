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
const int N = 3 + 4e5;

int lg2[N];

int main() {
    for (int i = 2; i < N; ++i) {
        lg2[i] = lg2[i / 2] + 1;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        int g = 0;
        for (auto &i : a) {
            g = gcd(g, i);
        }
        vector f(20, vector<int>(2 * n));
        for (int i = 0; i < n; ++i) {
            f[0][i] = f[0][i + n] = a[i];
        }
        for (int i = 1; i < 20; ++i) {
            for (int j = 0; j + (1 << i) - 1 < 2 * n; ++j) {
                f[i][j] = gcd(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
            }
        }

        auto query = [&](int l, int r) {
            int c = lg2[r - l + 1];
            return gcd(f[c][l], f[c][r - (1 << c) + 1]);
        };

        auto ok = [&](int o) {
            for (int i = 0; i < n; ++i) {
                if (query(i, i + o - 1) != g) {
                    return 0;
                }
            }
            return 1;
        };

        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (ok(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << r - 1 << endl;
    }
    return 0;
}