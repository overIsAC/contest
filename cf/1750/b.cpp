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

int n;
string s;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        LL u = count(s.begin(), s.end(), '0');
        LL v = count(s.begin(), s.end(), '1');
        LL ans = u * v;
        int o, oo = 0;
        for (int i = 0; i < n; ++i) {
            if (oo != s[i]) {
                oo = s[i];
                o = 1;
            } else {
                ++o;
            }
            ans = max(ans, (LL)o * o);
        }
        cout << ans << endl;
    }

    return 0;
}