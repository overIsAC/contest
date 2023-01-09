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

int ans[55][55];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int l = 1, r = n * n;
        int x = 1, y = 1;
        auto push = [&](int v) {
            ans[x][y] = v;
            ++y;
            if (y == n + 1) {
                y = 1;
                x += 1;
            }
        };
        while (l <= r) {
            if (l == r) {
                push(r);
                break;
            } else {
                push(l);
                push(r);
                ++l;
                --r;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                reverse(ans[i] + 1, ans[i] + n + 1);
            }
            for (int j = 1; j <= n; ++j) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}