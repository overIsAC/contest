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
    int x, y;
    cin >> x >> y;
    for (int i = 0; i <= x; ++i) {
        if (i * 1000 > y) {
            break;
        }
        int t = y - i * 1000;
        if (t % 2500) {
            continue;
        }
        int j = t / 2500;
        if (i + j <= x) {
            cout << x - i - j << ' ' << i << ' ' << j << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}