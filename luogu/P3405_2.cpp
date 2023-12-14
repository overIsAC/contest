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
    while (n--) {
        string a, b;
        cin >> a >> b;
        ++mp[{a.substr(0, 2), b}];
    }
    LL ans = 0, cnt = 0;
    for (auto& i : mp) {
        auto k = i.first;
        if (k.first == k.second) {
            // ans += (LL)i.second * (i.second - 1) / 2;
        } else {
            if (mp.count({k.second, k.first})) {
                cnt += (LL)i.second * mp[{k.second, k.first}];
            }
        }
    }
    ans += cnt / 2;
    cout << ans << endl;
    return 0;
}