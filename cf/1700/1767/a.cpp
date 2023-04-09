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
        int x[3], y[3];
        for (int i = 0; i < 3; ++i) {
            cin >> x[i] >> y[i];
        }
        sort(x, x + 3);
        sort(y, y + 3);
        if (x[0] < x[1] && x[1] < x[2]) {
            cout << "YES" << endl;
            continue;
        }
        if (y[0] < y[1] && y[1] < y[2]) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}