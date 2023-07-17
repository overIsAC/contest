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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }
        for (int i = 0; i < n; ++i) {
            int g = gcd(a[i], b[i]);
            if (!g) {
                continue;
            }
            a[i] /= g;
            b[i] /= g;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int u = a[i], v = b[i];
            if (!u && !v) {
                continue;
            }
            int g = 0;
            while (u) {
                if (v && u > 2 * v) {
                    if (u % (2 * v) == 0) {
                        g += u / (2 * v) * 3 - 3;
                        u %= 2 * v;
                        u += 2 * v;
                    } else {
                        g += u / (2 * v) * 3;
                        u %= 2 * v;
                    }
                } else {
                    int d = abs(u - v);
                    u = v;
                    v = d;
                    ++g;
                }
            }
            mx = max(g, mx);
        }
        for (int i = 0; i < n; ++i) {
            int t = mx;
            int u = a[i], v = b[i];
            while (t > 0) {
                if (v && u > 2 * v) {
                    if (u % (2 * v) == 0) {
                        t -= u / (2 * v) * 3 - 3;
                        u %= 2 * v;
                        u += 2 * v;
                    } else {
                        t -= u / (2 * v) * 3;
                        u %= 2 * v;
                    }
                } else {
                    if (!u) {
                        t %= 3;
                        if (!t) {
                            break;
                        }
                    }
                    --t;
                    int d = abs(u - v);
                    u = v;
                    v = d;
                }
            }
            a[i] = u;
            b[i] = v;
        }
        auto f = [&]() {
            int z = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == 0) {
                    ++z;
                }
                int d = abs(a[i] - b[i]);
                a[i] = b[i];
                b[i] = d;
            }
            return z == n;
        };
        int ok = 0;
        for (int i = 0; i < 3; ++i) {
            if (f()) {
                ok = 1;
                break;
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