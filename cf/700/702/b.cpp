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

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp[31];
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 30; ++j) {
            if (mp[j].count((1 << j) - a[i])) {
                ans += mp[j][(1 << j) - a[i]];
            }
            ++mp[j][a[i]];
        }
    }
    cout << ans << endl;
    return 0;
}
