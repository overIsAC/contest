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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int cnt[133] = {};
        int n;
        string s;
        cin >> n >> s;
        int k;
        char c;
        cin >> k;
        while (k--) {
            cin >> c;
            cnt[c] = 1;
        }
        int ans = 0;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[s[i]]) {
                ans = max(i - 1 - last + 1, ans);
                last = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}