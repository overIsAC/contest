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

string s;

void solve() {
    string temp;
    for (int i = 0; i < s.size(); i += 2) {
        if (i + 1 == s.size()) {
        }
        if (s[i] == s[i + 1]) {
            temp += s[i];
        } else {
            cout << temp;
            cout << max(s[i], s[i + 1]);
            if (i + 2 < s.size()) {
                cout << s.substr(i + 2);
            }
            cout << min(s[i], s[i + 1]);
            reverse(temp.begin(), temp.end());
            cout << temp << endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        sort(s.begin(), s.end());
        solve();
    }
    return 0;
}