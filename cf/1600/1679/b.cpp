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

int n, q, a[N];
int tag[N], tg, val;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    tg = -1;
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
    }
    for (int i = 1; i <= q; ++i) {
        int op, p, x;
        cin >> op;
        if (op == 1) {
            cin >> p >> x;
            if (tg > tag[p]) {
                sum -= val;
            } else {
                sum -= a[p];
            }
            sum += x;
            a[p] = x;
            tag[p] = i;
        } else {
            cin >> x;
            sum = (LL)x * n;
            val = x;
            tg = i;
        }
        cout << sum << endl;
    }
    return 0;
}