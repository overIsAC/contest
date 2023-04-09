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
        LL a, b;
        cin >> a >> b;
        LL ans = 1e18;
        LL u = 1e18, v = 1e18;
        vector<LL> ve;
        for (int i = 1; i * i <= 2e9; ++i) {
            ve.push_back(i);
            if (a / i) {
                ve.push_back(a / i);
            }
            if (b / i) {
                ve.push_back(b / i);
            }
        }
        sort(ve.begin(), ve.end());
        for (auto &i : ve) {
            u = min(u, a / i + !!(a % i));
            v = min(v, b / i + !!(b % i));
            ans = min(ans, u + v + i - 1);
        }
        cout << ans << endl;
    }
    return 0;
}