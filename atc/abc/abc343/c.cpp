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
    LL n;
    cin >> n;
    LL ans = 1;

    auto ok = [&](LL z) {
        string s = to_string(z);
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    };
    for (LL i = 1; i * i * i <= n; ++i) {
        if (ok(i * i * i)) {
            ans = i * i * i;
        }
    }
    cout << ans << endl;
    return 0;
}