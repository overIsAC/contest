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
const int N = 3 + 3e5;

int n, a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        LL l = 0, r = 1e15;

        auto ok = [&](LL v) {
            LL one = (v + 1) / 2, two = v / 2;
            bool flag = true;
            for (int i = 1; i < n; ++i) {
                LL x = a[n] - a[i];
                LL t = min(x / 2, two);
                x -= t * 2;
                two -= t;
                t = min(x, one);
                x -= t;
                one -= t;
                if (x > 1) {
                    return false;
                }
                if (x == 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
            one = (v + 1) / 2;
            two = v / 2;
            for (int i = 1; i <= n; ++i) {
                LL x = a[n] + 1 - a[i];
                LL t = min(x / 2, two);
                x -= t * 2;
                two -= t;
                t = min(x, one);
                x -= t;
                one -= t;
                if (x) {
                    return false;
                }
            }
            return true;
        };

        while (l < r) {
            LL mid = (l + r) / 2;
            if (ok(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}