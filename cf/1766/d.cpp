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
const int N = 3 + 1e7;

bool v[N];
int t, p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < N; ++i) {
        if (!v[i]) {
            p[++t] = i;
        }
        for (int j = 1; j <= t && i * p[j] < N; ++j) {
            v[i * p[j]] = true;
            if (i % p[j] == 0) {
                break;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        swap(x, y);
        if (x == y + 1) {
            cout << -1 << endl;
        } else if (__gcd(x, y) > 1) {
            cout << 0 << endl;
        } else {
            LL ans = 1e18;
            auto calc = [&](int v) -> LL { return (y + v - 1) / v * v; };
            LL a = x - y;
            if (!v[a]) {
                ans = min(ans, calc(a) - y);
            } else {
                LL b = a;
                for (int i = 1; i <= t && p[i] * p[i] <= b && p[i] <= a; ++i) {
                    if (a % p[i] == 0) {
                        ans = min(ans, calc(p[i]) - y);
                        while (a % p[i] == 0) {
                            a /= p[i];
                        }
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}