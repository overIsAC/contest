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

int n, q, a[N];
LL preSum[N], preXor[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            preSum[i] = preSum[i - 1] + a[i];
            preXor[i] = preXor[i - 1] ^ a[i];
        }

        auto calc = [&](int l, int r) {
            return (preSum[r] - preSum[l - 1]) - (preXor[r] ^ preXor[l - 1]);
        };

        while (q--) {
            int l, r;
            cin >> l >> r;
            int x = 1, y = n;
            for (int i = 1; i <= n; ++i) {
                if (calc(i, n) != calc(1, n)) {
                    continue;
                }

                int L = i, R = n;
                while (L < R) {
                    int mid = L + R >> 1;
                    if (calc(i, mid) == calc(1, n)) {
                        R = mid;
                    } else {
                        L = mid + 1;
                    }
                }
                if (R - i < y - x) {
                    x = i;
                    y = R;
                }
            }
            cout << x << ' ' << y << endl;
        }
    }
    return 0;
}