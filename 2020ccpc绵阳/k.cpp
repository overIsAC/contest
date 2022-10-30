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
const int N = 3 + 2e5;

int x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while (T--) {
        cout << "Case #" << ++Case << ": ";

        cin >> x;
        if (x % 2 == 1) {
            cout << 1 << endl;
        } else {
            int ans = INT_MAX;
            auto f = [&](int o) -> void {
                if (o % 2 == 1) {
                    ++o;
                }
                for (int i = -8; i <= 8; i += 2) {
                    int to = i + o;
                    if (to <= 1) {
                        continue;
                    }
                    int ab = x - to;
                    if (ab <= 1) {
                        continue;
                    }
                    int a = ab / 2;
                    int b = ab / 2;
                    if (a % 2 == 0) {
                        --a;
                        ++b;
                    }
                    for (int j = -2; j <= 10; j += 2) {
                        int aa = a + j;
                        int bb = b - j;
                        if (aa <= 1 || bb <= 1 || aa + bb + to != x) {
                            continue;
                        }
                        if (__gcd(aa, bb) == 1 && __gcd(aa, to) == 1 &&
                            __gcd(bb, to) == 1) {
                            ans =
                                min(ans, max({aa, bb, to}) - min({aa, bb, to}));
                        }
                    }
                }
            };

            f(x / 3);
            f(x / 2);
            if (ans == INT_MAX) {
                f(1);
                f(x);
            }

            int o = x / 2;
            if (o % 2 == 0) {
                ++o;
            }

            for (int i = -20; i <= 20; ++i) {
                int a = o, b = x - a;
                if (a <= 1 || b <= 1 || __gcd(a, b) != 1) {
                    continue;
                }
                ans = min(ans, abs(a - b));
            }

            if (ans == INT_MAX) {
                ans = -1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}