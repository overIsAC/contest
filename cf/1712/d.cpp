#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
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

int n, k, a[N];
int pre[N], suf[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        auto ok = [&](int v) {
            for (int i = 1; i <= n; ++i) {
                pre[i] = pre[i - 1];
                if (a[i] * 2 < v) {
                    ++pre[i];
                }
            }
            suf[n + 1] = 0;
            for (int i = n; i >= 1; --i) {
                suf[i] = suf[i + 1];
                if (a[i] * 2 < v) {
                    ++suf[i];
                }
            }
            int c = 1e9;
            for (int i = 1; i < n; ++i) {
                c = min(c, pre[i - 1] + suf[i + 2] + (a[i] < v) + (a[i + 1] < v));
            }
            return c <= k;
        };
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (ok(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}