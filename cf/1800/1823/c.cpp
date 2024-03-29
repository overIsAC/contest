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
        int ans = 0, n, a;
        cin >> n;
        map<int, int> mp;
        while (n--) {
            cin >> a;
            for (int i = 2; i * i <= a; ++i) {
                while (a % i == 0) {
                    a /= i;
                    ++mp[i];
                }
            }
            if (a > 1) {
                ++mp[a];
            }
        }
        int cnt = 0;
        for (auto i : mp) {
            if (i.second % 2) {
                ++cnt;
            }
            ans += i.second / 2;
        }
        ans += cnt / 3;
        cout << ans << endl;    
    }
    return 0;
}