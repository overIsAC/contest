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

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        for (int i = 1; i <= 8; ++i) {
            for (int j = 'a'; j <= 'h'; ++j) {
                if (i == s[1] - '0' || j == s[0]) {
                    string t = (char)j + to_string(i);
                    if (t == s) {
                        continue;
                    }
                    cout << t << endl;
                }
            }
        }
    }
    return 0;
}