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
        int n, a, c;
        cin >> n >> c;
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            ++mp[a];
        }
        int ans = 0;
        for (auto &i : mp) {
            ans += min(i.second, c);
        }
        cout << ans << endl;
    }

    return 0;
}