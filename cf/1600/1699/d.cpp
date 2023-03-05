#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e3;

int n, a[N];
bool ok[N][N];
int cnt[N];
int dp[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            int mx = 0;
            memset(cnt, 0, sizeof(cnt));
            for (int j = i; j <= n; ++j) {
                mx = max(mx, ++cnt[a[j]]);
                ok[i][j] = (j - i + 1) % 2 == 0 && mx * 2 <= j - i + 1;
            }
        }
        auto f = [&](int l, int r) -> bool {
            if (l > r) return 1;
            return ok[l][r];
        };
        memset(dp, -0x3f, sizeof(dp));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (f(1, i - 1)) dp[i] = 1;
            for (int j = 1; j < i; ++j) {
                if (f(j + 1, i - 1) && a[i] == a[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (f(i + 1, n)) {
                ans = max(ans, dp[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}