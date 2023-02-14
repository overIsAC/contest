#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL a, b, c;
        cin >> a >> b >> c;
        if (a >= 3 || (b >= 3 && c >= 3)) {
            cout << (a + 2 * b + 3 * c) % 2 << endl;
            continue;
        }
        int ans = a + 2 * b + 3 * c;
        for (int i = 0; i <= 10; ++i) {
            if (i > a) {
                break;
            }
            if (a - i & 1) {
                continue;
            }
            for (int j = 0; j <= 10; ++j) {
                if (j > b) {
                    break;
                }
                if (b - j & 1) {
                    continue;
                }
                for (int k = 0; k <= 10; ++k) {
                    if (k > c) {
                        break;
                    }
                    if (c - k & 1) {
                        continue;
                    }
                    ans = min<int>(ans, abs(i + 2 * j + 3 * k));
                    ans = min<int>(ans, abs(i + 2 * j - 3 * k));
                    ans = min<int>(ans, abs(i - 2 * j + 3 * k));
                    ans = min<int>(ans, abs(i - 2 * j - 3 * k));
                    ans = min<int>(ans, abs(-i + 2 * j + 3 * k));
                    ans = min<int>(ans, abs(-i + 2 * j - 3 * k));
                    ans = min<int>(ans, abs(-i - 2 * j + 3 * k));
                    ans = min<int>(ans, abs(-i - 2 * j - 3 * k));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}