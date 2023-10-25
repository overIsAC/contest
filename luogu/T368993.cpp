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

int a, b, c, m;

int main() {
    cin >> a >> b >> c >> m;
    int x = 0, y = 0, z = 0;
    while (m--) {
        int op, k;
        cin >> op >> k;
        if (op == 1) {
            x = max(x, k);
        } else if (op == 2) {
            y = max(y, k);
        } else {
            z = max(z, k);
        }
        cout << (LL)(a - x) * (b - y) * (c - z) << endl;
    }
    return 0;
}