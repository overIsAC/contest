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
    LL p;
    cin >> s >> p;
    if (p <= s.size()) {
        cout << s[p - 1];
        return;
    }
    vector<char> stk;
    int nowLength = s.size();
    for (int i = 0; i < s.size(); ++i) {
        while (stk.size() && stk.back() > s[i]) {
            stk.pop_back();
            p -= nowLength;
            nowLength -= 1;
            if (p <= nowLength) {
                if (p <= stk.size()) {
                    cout << stk[p - 1];
                    return;
                }
                p -= stk.size();
                cout << s[p - 1 + i];
                return;
            }
        }
        stk.push_back(s[i]);
        if (p <= nowLength) {
            if (p <= stk.size()) {
                cout << stk[p - 1];
                return;
            }
            p -= stk.size();
            cout << s[p - 1 + i];
            return;
        }
    }
    while (p > nowLength) {
        p -= nowLength;
        nowLength -= 1;
    }
    cout << stk[p - 1];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}