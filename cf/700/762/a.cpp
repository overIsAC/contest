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

LL stk[N], top;
LL n, k;

int main() {
    cin >> n >> k;
    for (LL i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            --k;
            if (!k) {
                cout << i << endl;
                return 0;
            }
            if (i * i != n) {
                stk[++top] = n / i;
            }
        }
    }
    if (k <= top) {
        cout << stk[top - k + 1] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}