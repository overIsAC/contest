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

int n;
LL dp[N][2];
int a[N], s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        auto get = [&](int i) -> PII {
            int x = 0, y = a[i];
            if (a[i] > s) {
                x = s;
                y = a[i] - s;
                if (x > y) {
                    swap(x, y);
                }
            };
            return {x, y};
        };
        auto o = get(2);
        dp[2][0] = (LL)a[1] * o.first;
        dp[2][1] = (LL)a[1] * o.second;
        for (int i = 3; i <= n; ++i) {
            auto u = get(i - 1), v = get(i);
            dp[i][0] = min(dp[i - 1][0] + (LL)u.second * v.first, dp[i - 1][1] + (LL)u.first * v.first);
            dp[i][1] = min(dp[i - 1][0] + (LL)u.second * v.second, dp[i - 1][1] + (LL)u.first * v.second);
        }
        o = get(n - 1);
        LL ans = min(dp[n - 1][0] + (LL)o.second * a[n], dp[n - 1][1] + (LL)o.first * a[n]);
        cout << ans << endl;
    }
    return 0;
}