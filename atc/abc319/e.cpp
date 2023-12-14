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
const int N = 3 + 2e5;

int n, x, y;
int p[N], t[N];
LL ans[1000];

LL calc(int z) {
    LL ans = z;
    for (int i = 1; i < n; ++i) {
        ans = (ans + p[i] - 1) / p[i] * p[i];
        ans += t[i];
    }
    ans += y;
    return ans - z;
}

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i < n; ++i) {
        cin >> p[i] >> t[i];
    }
    for (int i = 0; i < 840; ++i) {
        ans[i] = calc(i);
        // cout << i << ' ' << ans[i] << endl;
    }
    // cout << endl;
    int q;
    cin >> q;
    while (q--) {
        int z;
        cin >> z;
        z += x;
        cout << z + ans[z % 840] << endl;
    }

    return 0;
}