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
        for (int i = 0; i < 8; ++i) {
            cin >> s[i];
        }
        for (int i = 1; i < 7; ++i) {
            for (int j = 1; j < 7; ++j) {
                if (s[i][j] == '#' && s[i - 1][j - 1] == '#' && s[i - 1][j + 1] == '#') {
                    cout << i + 1 << ' ' << j + 1 << endl;
                }
            }
        }
    }
    return 0;
}