#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
string s;

int calc(char c) {
    int l = 0, r = n - 1;
    int ans = 0;
    // cout << c << endl;
    while (l <= r) {
        int u = 0, v = 0;
        while (l <= r && s[l] == c) {
            ++l;
            ++u;
        }
        while (l <= r && s[r] == c) {
            --r;
            ++v;
        }
        
        if (l > r) {
            break;
        }
        ans += abs(u - v);
        // cout << l << ' ' << r << endl;
        if (s[l] == s[r]) {
            ++l;
            --r;
        } else {
            return 1e9;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int ans = 1e9;
        cin >> n >> s;
        for (char i = 'a'; i <= 'z'; ++i) {
            ans = min(ans, calc(i));
        }
        if (ans > 1e7) {
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}
// abbabbbb