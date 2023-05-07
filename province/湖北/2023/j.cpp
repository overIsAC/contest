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

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (accumulate(a + 1, a + n + 1, 0LL) < 0) {
        cout << -1 << endl;
        return 0;
    }
    LL mx = -1e18, ans = 0, sum = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (cnt + sum < 0) {
            if (mx <= 0) {
                cout << -1 << endl;
                return 0;
            }
            LL v = abs(cnt + sum);
            v = (v + mx - 1) / mx;
            ans += v;
            cnt += v * mx;
        }
        ++ans;
        mx = max(sum, mx);
        cnt += sum;
    }
    cout << ans << endl;
    return 0;
}