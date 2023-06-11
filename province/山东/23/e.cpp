#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3 + 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        LL n, k, m, a, b;
        cin >> n >> k >> m >> a >> b;
        if (n % m == 0) {
            cout << 0 << endl;
            continue;
        }
        if (k == 1) {
            cout << -1 << endl;
            continue;
        }
        int i = 0;
        LL ans = LLONG_MAX;
        do {
            __int128_t l = n, r = n;
            LL cnt = i * b;

            while (cnt < ans) {
                cnt += a;
                l *= k;
                r *= k;
                r += k - 1;

                __int128_t t = r / m * m;
                if (l <= t) {
                    ans = min(ans, cnt);
                    break;
                }
            }

            n /= k;
            ++i;

            if (n % m == 0) {
                ans = min(ans, i * b);
                break;
            }
        } while (n);

        cout << ans << endl;
    }
    return 0;
}