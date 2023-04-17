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
const int N = 3 + 2e5;

char s[N];
int pre0[2][N];
int pre1[2][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        int n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            pre0[0][i] = pre0[0][i - 1];
            pre0[1][i] = pre0[1][i - 1];
            pre1[0][i] = pre1[0][i - 1];
            pre1[1][i] = pre1[1][i - 1];
            if (s[i] == '0') {
                ++pre0[i & 1][i];
            }
            if (s[i] == '1') {
                ++pre1[i & 1][i];
            }
        }
        LL ans = 0;
        auto ok = [&](int l, int r) {
            if (pre0[0][r] - pre0[0][l - 1] && pre1[0][r] - pre1[0][l - 1]) {
                return false;
            }
            if (pre0[1][r] - pre0[1][l - 1] && pre1[1][r] - pre1[1][l - 1]) {
                return false;
            }
            if (pre0[0][r] - pre0[0][l - 1] && pre0[1][r] - pre0[1][l - 1]) {
                return false;
            }
            if (pre1[0][r] - pre1[0][l - 1] && pre1[1][r] - pre1[1][l - 1]) {
                return false;
            }
            return true;
        };
        for (int i = 1; i <= n; ++i) {
            int l = 1, r = i;
            while (l < r) {
                int mid = l + r >> 1;
                if (ok(mid, i)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            // cout << r << ' ' << i << endl;
            ans += i - r + 1;
        }
        cout << ans << endl;
    }

    return 0;
}