#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

LL x;

LL calc(int i, int j) {
    LL ans = 0;
    if (x >> i & 1) {
        ans |= 1 << i;
    } else {
        return 1LL << 40;
    }
    if ((x >> j & 1) == 0) {
        ans |= 1 << j;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> x;
        LL ans = 1LL << 40;
        for (int i = 0; i <= 30; ++i) {
            for (int j = 0; j <= 30; ++j) {
                LL v = calc(i, j);
                if ((v & x) > 0 && (v ^ x) > 0) {
                    ans = min(ans, v);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}