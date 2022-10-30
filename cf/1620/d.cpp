#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int th = a[n] / 3;
        int ans = a[n];
        for (int i = 0; i <= 3; ++i) {
            for (int j = 0; j <= 3; ++j) {
                for (int k = max(0, th - 3); k <= th; ++k) {
                    bool ok = true;
                    for (int u = 1; u <= n; ++u) {
                        bool g = false;
                        for (int q = 0; q <= i; ++q) {
                            for (int w = 0; w <= j; ++w) {
                                if (a[u] - q - 2 * w >= 0 &&
                                    (a[u] - q - 2 * w) % 3 == 0 &&
                                    (a[u] - q - 2 * w) / 3 <= k) {
                                    g = true;
                                    break;
                                }
                            }
                        }
                        if (g == false) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        ans = min(ans, i + j + k);
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
