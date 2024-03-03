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
        string s[8];
        for (auto& i : s) {
            cin >> i;
        }
        char ans = 'B';
        for (int i = 0; i < 8; ++i) {
            set<char> st;
            for (int j = 0; j < 8; ++j) {
                st.insert(s[i][j]);
            }
            if (st.size() == 1 && *st.begin() == 'R') {
                ans = *st.begin();
            }
        }
        cout << ans << endl;
    }
    return 0;
}