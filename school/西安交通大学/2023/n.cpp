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

int n, m;
int a, b, c;
int x[N];

int main() {
    cin >> n >> m;
    cin >> a >> b >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    LL ans = (LL)x[1] * b;
    ans += (LL)(x[1] + 1) * a;
    int flag = 0;
    // cout << ans << endl;
    for (int i = 2; i <= n; ++i) {
        int d = (x[i] - x[i - 1] + m) % m;
        if (d <= 0) {
            d += m;
        }
        if (d != 1) {
            if (!flag) {
                ans += c;
                flag = 1;
            }
        }
        ans += (LL)d * a + (LL)(d - 1) * b;
        // cout << i << ' ' << d << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}