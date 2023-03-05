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
        string s;
        cin >> n >> s;
        int x = 0, y = 0;
        bool ok = false;
        for (auto &i : s) {
            if (i == 'U') {
                ++y;
            } else if (i == 'D') {
                --y;
            } else if (i == 'R') {
                ++x;
            } else {
                --x;
            }
            if (x == 1 && y == 1) {
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