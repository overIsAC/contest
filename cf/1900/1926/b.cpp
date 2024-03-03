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
        int n;
        cin >> n;
        vector<string> s(n);
        int y = 100, x1 = 100, x2 = -1;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == '1') {
                    x1 = min(x1, i);
                    x2 = max(x2, i);
                    y = min(y, j);
                }
            }
        }
        if (s[x1][y] == '1' && s[x2][y] == '1') {
            cout << "SQUARE" << endl;
        } else {
            cout << "TRIANGLE" << endl;
        }
    }
    return 0;
}