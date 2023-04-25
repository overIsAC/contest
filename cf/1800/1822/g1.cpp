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
const int N = 3 + 2e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            ++mp[a[i]];
        }
        LL ans = 0;
        auto calc = [&](int x) {
            return (LL)x * (x - 1) * (x - 2);
        };
        for (auto &i : mp) {
            ans += calc(i.second);
            for (int j = 2; j * j * i.first <= 1e6; ++j) {
                if (mp.count(j * j * i.first) && mp.count(j * i.first)) {
                    ans += (LL)i.second * mp[j * i.first] * mp[j * j * i.first];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}