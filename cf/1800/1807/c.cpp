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
        int a, n;
        int u = 0, v = 0;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> mp;
        mp[s[0]] = '0';
        s[0] = '0';
        for (int i = 1; i < n; ++i) {
            if (!mp.count(s[i])) {
                mp[s[i]] = s[i - 1] ^ 1;
            }
            s[i] = mp[s[i]];
        }
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                ok = false;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}