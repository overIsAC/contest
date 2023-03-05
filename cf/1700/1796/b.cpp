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
        string s, t;
        cin >> s >> t;
        if (s[0] == t[0]) {
            cout << "YES" << endl;
            cout << s[0] << '*' << endl;
        } else if (s.back() == t.back()) {
            cout << "YES" << endl;
            cout << '*' << s.back() << endl;
        } else {
            string ans;
            for (int i = 0; i + 1 < s.size(); ++i) {
                for (int j = 0; j + 1 < t.size(); ++j) {
                    if (s[i] == t[j] && s[i + 1] == t[j + 1]) {
                        ans = s[i];
                        ans += s[i + 1];
                    }
                }
            }
            if (ans.size()) {
                cout << "YES" << endl;
                cout << "*" << ans << '*' << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}