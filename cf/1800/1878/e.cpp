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
const int N = 3 + 2e5;

int n, a[N], q;
int pre[33][N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 30; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre[i][j] = a[j] >> i & 1;
            pre[i][j] += pre[i][j - 1];
        }
    }

    cin >> q;
    int l, k;
    while (q--) {
        cin >> l >> k;

        auto calc = [&](int r) {
            int ans = 0;
            for (int i = 0; i < 30; ++i) {
                if (pre[i][r] - pre[i][l - 1] == r - l + 1) {
                    ans += 1 << i;
                }
            }
            return ans;
        };
        if (calc(l) < k) {
            cout << -1 << ' ';
            continue;
        }
        int L = l, R = n;
        while (L < R) {
            int mid = L + R + 1 >> 1;
            if (calc(mid) >= k) {
                L = mid;
            } else {
                R = mid - 1;
            }
        }
        cout << R << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}