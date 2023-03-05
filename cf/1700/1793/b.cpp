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
        LL x, y;
        cin >> x >> y;
        cout << abs(x - y) * 2 << endl;
        for (int i = min(x, y); i <= max(x, y); ++i) {
            cout << i << ' ';
        }
        for (int i = max(x, y) - 1; i > min(x, y); --i) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}