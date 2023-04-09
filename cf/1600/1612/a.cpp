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

int x, y;

void solve() {
    for (int i = 0; i <= 50; ++i) {
        for (int j = 0; j <= 50; ++j) {
            if (2 * i + 2 * j == x + y) {
                if (2 * abs(i - x) + 2 * abs(j - y) == x + y) {
                    cout << i << ' ' << j << endl;
                    return;
                }
            }
        }
    }
    cout << "-1 -1" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        solve();
    }
    return 0;
}