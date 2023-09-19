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
    string s;
    cin >> s;
    if (s[0] == '0') {
        cout << "NO" << endl;
        return;
    }
    vector<int> stk;
    int exist = 0;
    for (auto &i : s) {
        if (i == '+') {
            stk.push_back(0);
        } else if (i == '-') {
            if (exist == stk.size()) {
                exist = 0;
            }
            int v = stk.back();
            stk.pop_back();
            if (v && stk.size()) {
                stk.back() = 1;
            }
        } else if (i == '1') {
            if (exist > 0) {
                cout << "NO" << endl;
                return;
            }
            if (stk.size()) {
                stk.back() = 1;
            }
        } else {
            if (stk.size() && stk.back()) {
                cout << "NO" << endl;
                return;
            }
            if (stk.size() <= 1) {
                cout << "NO" << endl;
                return;
            }
            if (exist) {
                continue;
            }
            exist = stk.size();
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}