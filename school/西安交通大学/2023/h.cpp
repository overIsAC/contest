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

int n;
string s[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    char p = 0;
    set<char> cs;
    for (int i = 1; i <= n; ++i) {
        cs.insert(s[i].begin(), s[i].end());
    }
    for (char i : cs) {
        set<string> st;
        for (int j = 1; j <= n; ++j) {
            string temp;
            for (auto &k : s[j]) {
                if (k == i) {
                    temp += k;
                    continue;
                }
            }
            st.insert(temp);
        }
        if (st.size() == n) {
            p = i;
            break;
        }
    }
    if (!p) {
        cout << "no" << endl;
        return 0;
    }
    cout << "yes" << endl;

    for (auto &i : cs) {
        if (i == p) {
            continue;
        }
        cout << i;
    }
    cout << p << endl;
    return 0;
}