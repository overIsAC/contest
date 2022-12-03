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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int t, k, n, d, a[N];
LL x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> x >> t >> k >> n >> d;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int last = 1;
        bool ok = false;
        LL nx = x;
        for (int i = 1; i <= n; ++i) {
            if (a[i] <= d) {
                --x;
            } else {
                ++x;
            }
            if (x <= k) {
                if (i - last + 1 >= t) {
                    ok = true;
                    break;
                }
            } else {
                last = i + 1;
            }
        }
        if (x < nx) {
            ok = true;
        }
        if (x == nx) {
            if (last == 1) {
                ok = true;
            } else {
                for (int i = 1; i <= n; ++i) {
                    if (a[i] <= d) {
                        --x;
                    } else {
                        ++x;
                    }
                    if (x <= k) {
                        if (i + n - last + 1 >= t) {
                            ok = true;
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}