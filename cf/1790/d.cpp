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
        int ans = 0;
        int last = 0, cnt = 0;
        for (auto &i : mp) {
            if (last + 1 != i.first) {
                ans += i.second;
            } else {
                if (cnt < i.second) {
                    ans += i.second - cnt;
                }
            }
            last = i.first;
            cnt = i.second;
        }
        cout << ans << endl;
    }
    return 0;
}