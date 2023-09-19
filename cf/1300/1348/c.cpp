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

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    if (k == 1) {
        cout << s << endl;
        return;
    }
    if (s[0] == s[k - 1]) {
        if (k < n && s[k] == s.back()) {
            for (int i = 0; i < n; i += k) {
                cout << s[i];
            }
            cout << endl;
        } else {
            cout << s.substr(k - 1) << endl;
        }
    } else {
        cout << s[k - 1] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}