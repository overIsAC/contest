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
        int ans = 0;
        for (int i = 0; i < s.size();) {
            if (i + 1 < n && s[i + 1] == '@') {
                i += 1;
                ++ans;
                continue;
            }
            if (i + 2 < n && s[i + 2] == '@') {
                i += 2;
                ++ans;
                continue;
            }
            if (i + 1 < n && s[i + 1] == '.') {
                i += 1;
                continue;
            }
            if (i + 2 < n && s[i + 2] == '.') {
                i += 2;
                continue;
            }
            break;
        }
        cout << ans << endl;
    }
    return 0;
}