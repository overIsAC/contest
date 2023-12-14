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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

void solve() {
    string s;
    cin >> s;
    vector<int> vis(s.size());
    vector<int> stk[2];
    for (int i = 0; i < s.size(); ++i) {
        if (islower(s[i])) {
            if (s[i] == 'b') {
                if (stk[0].size()) {
                    stk[0].pop_back();
                }
            } else {
                stk[0].push_back(i);
            }
        } else {
            if (s[i] == 'B') {
                if (stk[1].size()) {
                    stk[1].pop_back();
                }
            } else {
                stk[1].push_back(i);
            }
        }
    }
    for (auto& i : stk) {
        for (auto& j : i) {
            vis[j] = 1;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if (vis[i]) {
            cout << s[i];
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}