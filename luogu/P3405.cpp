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
    int n;
    cin >> n;
    map<pair<string, string>, int> mp;
    LL ans = 0;
    while (n--) {
        string a, b;
        cin >> a >> b;
        if (a.substr(0, 2) != b) {
            ans += mp[{b, a.substr(0, 2)}];
        }
        ++mp[{a.substr(0, 2), b}];
    }
    cout << ans << endl;
    return 0;
}