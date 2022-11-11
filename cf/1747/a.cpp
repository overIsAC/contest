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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a, z = 0;
        cin >> n;
        vector<LL> u, v;
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            if (a == 0)
                ++z;
            else if (a < 0)
                u.push_back(-a);
            else
                v.push_back(a);
        }
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        LL ans = accumulate(u.begin(), u.end(), 0LL) -
                 accumulate(v.begin(), v.end(), 0LL);
        ans = abs(ans);
        if (u.size() == 0 || v.size() == 0) {
            if (!z) {
                if (u.size()) {
                    z -= u[0];
                } else {
                    z -= v[0];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}