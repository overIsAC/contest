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

int n;
int l[N], r[N], c[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        map<PII, int> mp;
        int R = 0, rc = 0, L = 2e9, lc = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> l[i] >> r[i] >> c[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (l[i] < L) {
                L = l[i];
                lc = c[i];
            } else if (l[i] == L) {
                lc = min(c[i], lc);
            }
            if (r[i] > R) {
                R = r[i];
                rc = c[i];
            } else if (r[i] == R) {
                rc = min(c[i], rc);
            }
            if (mp.count({l[i], r[i]})) {
                mp[{l[i], r[i]}] = min(mp[{l[i], r[i]}], c[i]);
            } else {
                mp[{l[i], r[i]}] = c[i];
            }
            int ans = lc + rc;
            if (mp.count({L, R})) {
                ans = min(ans, mp[{L, R}]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}