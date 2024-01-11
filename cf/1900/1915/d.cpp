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
const int N = 3 + 1e3;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<char> V = {'a', 'e'};
    vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
        if (V.count(s[i])) {
            vis[i - 1] = 1;
        }
    }
    string ans;
    for (int i = 0; i < n; ++i) {
        if (V.count(s[i])) {
            string t;
            t += s[i - 1];
            t += s[i];
            if (i + 1 < n && !vis[i + 1]) {
                t += s[i + 1];
            }
            if (ans.size()) {
                ans += '.';
            }
            ans += t;
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}