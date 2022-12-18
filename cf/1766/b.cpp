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
const int N = 3 + 2e6;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        set<pair<char, char>> st;
        bool ok = false;
        for (int i = 1; i + 1 < n; ++i) {
            if (st.count({s[i], s[i + 1]})) {
                ok = true;
                break;
            }
            st.insert({s[i - 1], s[i]});
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}