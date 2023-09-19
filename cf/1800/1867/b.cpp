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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            cnt += s[i] != s[j];
        }
        string ans;
        for (int i = 0; i <= n; ++i) {
            if (i < cnt) {
                ans += '0';
            } else {
                if (i > n - cnt) {
                    ans += '0';
                    continue;
                }
                if (n % 2) {
                    ans += '1';
                } else {
                    if (i - cnt & 1) {
                        ans += '0';
                    } else {
                        ans += '1';
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}