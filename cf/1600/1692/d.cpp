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
        char s[222];
        cin >> s;
        int h = (s[0] - '0') * 10 + s[1] - '0';
        int m = (s[3] - '0') * 10 + s[4] - '0';
        int x;
        cin >> x;
        h = h * 60 + m;
        set<string> st;

        auto calc = [&](int h) -> string {
            char z[111];
            sprintf(z, "%02d%02d", h / 60, h % 60);
            string s = z;
            string t = s;
            reverse(s.begin(), s.end());
            if (s == t) {
                return s;
            } else {
                return "";
            }
        };

        for (int i = 0; i < 3600; ++i) {
            h += x;
            h %= 24 * 60;
            st.insert(calc(h));
        }
        // for (auto& i : st) {
        //     cout << i << endl;
        // }
        st.insert("");
        cout << st.size() - 1 << endl;
    }
    return 0;
}