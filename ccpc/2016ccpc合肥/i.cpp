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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

LL L, R;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &L, &R);
        bool lim1 = true, lim2 = true;
        LL x = R, y = 0;
        for (int i = 60; i >= 0; --i) {
            int down = lim1 ? (L >> i & 1) : 0;
            int up = lim2 ? (R >> i & 1) : 1;

            if (!(x >> i & 1)) {
                if (down <= 1 && 1 <= up) {
                    y |= 1LL << i;
                    lim1 = lim1 && 1 == down;
                    lim2 = lim2 && 1 == up;
                    continue;
                }
            }

            for (LL j = down; j <= up; ++j) {
                y |= j << i;
                lim1 = lim1 && j == down;
                lim2 = lim2 && j == up;
                break;
            }
        }
        printf("%lld\n", x | y);
    }
    return 0;
}