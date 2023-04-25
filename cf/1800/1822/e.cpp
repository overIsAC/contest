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
    int T;
    cin >> T;
    while (T--) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        map<int, int> mp;
        for (auto &i : s) {
            ++mp[i];
        }
        int mx = 0;
        for (auto &i : mp) {
            mx = max(mx, i.second);
        }
        if (mx * 2 > n || n % 2) {
            cout << -1 << endl;
            continue;
        }
        int t = 0;
        mp.clear();
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            if (s[i] == s[j]) {
                ++mp[s[i]];
                ++t;
            }
        }
        mx = 0;
        for (auto &i : mp) {
            mx = max(mx, i.second);
        }
        cout << max((t + 1) / 2, mx) << endl;
    }
    return 0;
}