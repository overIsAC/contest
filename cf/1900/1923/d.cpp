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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<LL> pre(n + 1);
        vector<int> same(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + a[i];
            same[i] += same[i - 1];
            if (a[i] == a[i - 1]) {
                ++same[i];
            }
        }

        auto ok = [&](int l, int r, int v) -> int {
            if (pre[r] - pre[l - 1] > v) {
                if (l == r) {
                    return 1;
                }
                if (same[r] - same[l] < r - l) {
                    return 1;
                } else {
                    if (a[r] > v) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
            return 0;
        };

        for (int i = 1; i <= n; ++i) {
            int ans = 1e9;
            if (i > 1) {
                int l = 1, r = i - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (ok(mid, i - 1, a[i])) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                if (ok(r, i - 1, a[i])) {
                    ans = min(ans, i - r);
                }
            }
            if (i < n) {
                int l = i + 1, r = n;
                while (l < r) {
                    int mid = l + r >> 1;
                    if (ok(i + 1, mid, a[i])) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                if (ok(i + 1, r, a[i])) {
                    ans = min(ans, r - i);
                }
            }
            if (ans == 1e9) {
                ans = -1;
            }
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}