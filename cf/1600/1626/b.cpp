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
        string ans;
        for (int i = (int)s.size() - 2; i >= 0; --i) {
            if (s[i] - '0' + s[i + 1] - '0' >= 10) {
                ans = s.substr(0, i) + to_string(s[i] - '0' + s[i + 1] - '0') + s.substr(i + 2);
                break;
            }
        }
        if (ans.size()) {
            cout << ans << endl;
            continue;
        }
        cout << s[0] + s[1] - '0' - '0';
        for (int i = 2; i < s.size(); ++i) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}