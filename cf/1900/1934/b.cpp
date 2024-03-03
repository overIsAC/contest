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
        int n;
        cin >> n;
        int ans = n;
        for (int i = 0; i <= 10; ++i) {
            for (int j = 0; j <= 5; ++j) {
                for (int k = 0; k <= 3; ++k) {
                    for (int q = 0; q <= 2; ++q) {
                        int w = i * 3 + j * 6 + k * 10 + q * 15;
                        if (w <= n) {
                            ans = min(ans, i + j + k + q + (n - w) / 15 + (n - w) % 15);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}