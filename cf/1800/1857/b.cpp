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
const int N = 3 + 2e5;

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<int> vis(s.size());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] > '9') {
            s[i] = '0';
            if (i + 1 < s.size()) {
                ++s[i + 1];
            } else {
                s.push_back('1');
                vis.push_back(0);
            }
        }
        if (s[i] >= '5') {
            vis[i] = 1;
            if (i + 1 < s.size()) {
                ++s[i + 1];
            } else {
                s.push_back('1');
                vis.push_back(0);
            }
        }
    }
    reverse(s.begin(), s.end());
    reverse(vis.begin(), vis.end());
    string ans;
    int flag = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (vis[i]) {
            flag = 1;
        }
        if (flag) {
            ans += '0';
        } else {
            ans += s[i];
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