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
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        int n;
        cin >> n >> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt[128] = {};
            int mx = 0, c = 0;
            for (int j = 0; j < 26 * 26 && i + j < n; ++j) {
                if (!cnt[s[i + j]]) {
                    ++c;
                }
                mx = max(mx, ++cnt[s[i + j]]);
                if (c >= mx) {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}