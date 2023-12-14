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

void solve() {
    string s, t;
    cin >> s >> t;
    map<char, int> ms, mt;
    for (auto& i : s) {
        ++ms[i];
    }
    for (auto& i : t) {
        ++mt[i];
    }
    int ans = 1e9;
    for (auto [x, y] : mt) {
        ans = min(ans, ms[x] / y);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}