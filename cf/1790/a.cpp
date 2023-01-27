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
        cin >> s;
        string t = "314159265358979323846264338327";
        int ans = 0;
        for (int i = 0; i < s.size() && i < 30; ++i) {
            if (s[i] == t[i]) {
                ++ans;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}