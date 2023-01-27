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
const int N = 3 + 2e5;

LL n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        bool ok = true;
        for (int i = 0; i < 33; ++i) {
            if ((n >> i & 1) && (n >> (i + 1) & 1)) {
                ok = false;
            }
        }
        if (!ok || n % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        LL a = 0, b = 0;
        for (int i = 0; i < 33; ++i) {
            if (n >> i & 1) {
                a |= 1 << i;
                a |= 1 << (i - 1);
                b |= 1 << (i - 1);
            }
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}