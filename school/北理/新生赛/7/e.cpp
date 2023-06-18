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

int n, a[N];
LL pre[N], k;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    auto ok = [&](LL v) {
        LL kk = k;
        for (int i = 1, j = 1; i <= n; ++i) {
            while (pre[i] - pre[j - 1] > v) {
                ++j;
            }
            kk -= i - j + 1;
            if (kk <= 0) {
                return 1;
            }
        }
        return 0;
    };
    
    LL L = 1, R = pre[n];
    while (L < R) {
        LL mid = L + R >> 1;
        if (ok(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << R << endl;
    return 0;
}