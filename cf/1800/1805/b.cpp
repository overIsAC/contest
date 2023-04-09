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
        string s;
        cin >> s;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] <= s[p]) {
                p = i;
            }
        }
        cout << s[p];
        for (int i = 0; i < n; ++i) {
            if (i == p) {
                continue;
            }
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}