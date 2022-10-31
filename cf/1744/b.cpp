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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], q;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        LL sum = 0;
        int o[2] = {};
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
            o[a[i] & 1] += 1;
        }
        while (q--) {
            int op, x;
            cin >> op >> x;
            if (op == 0) {
                sum += o[0] * x;
                if (x & 1) {
                    o[1] += o[0];
                    o[0] = 0;
                }
            } else {
                sum += o[1] * x;
                if (x & 1) {
                    o[0] += o[1];
                    o[1] = 0;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}