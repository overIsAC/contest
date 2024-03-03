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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        int ans = 0;
        map<int, int> mp;
        for (auto& i : a) {
            int z = 0;
            for (int j = 0; j < 31; ++j) {
                if (i >> j & 1) {
                } else {
                    z |= 1 << j;
                }
            }
            if (mp[z]) {
                --mp[z];
            } else {
                ++mp[i];
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}