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
        int n, m;
        cin >> n >> m;
        cin >> s >> t;
        auto check = [&]() {
           for (int i = 1; i < s.size(); ++i) {
                if (s[i] == s[i - 1]) {
                    return false;
                }
            }
            for (int i = 1; i < t.size(); ++i) {
                if (t[i] == t[i - 1]) {
                    return false;
                }
            }
            return true;
        };
        bool ok = false;
        while (s.back() > 1) {
            t.push_back(s.back());
            s.pop_back();
            if (check()) {
                ok = true;
            }
        }
        while (t.back() > 1) {
            s.push_back(t.back());
            t.pop_back();
            if (check()) {
                ok = true;
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