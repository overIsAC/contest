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
const int N = 3 + 2e5;

int n;
PII a[N];
LL dp[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n * 2; ++i) {
        cin >> a[i].first;
        a[i].second = i - 1;
    }
    sort(a + 1, a + n * 2 + 1);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    auto f = [&](int i, int j) {
        if ((a[i].second ^ 1) == a[j].second) {
            return 0;
        }
        return 1;
    };
    auto transfer = [&](int L, int R) {
        if (!f(L, R)) {
            return;
        }
        LL cnt = a[R].first - a[L].first;
        for (int i = L + 1; i + 1 < R; i += 2) {
            if (!f(i, i + 1)) {
                return;
            }
            cnt += a[i + 1].first - a[i].first;
        }
        dp[R] = min(dp[R], dp[L - 1] + cnt);
    };
    for (int i = 2; i <= n * 2; i += 2) {
        for (int j = 2; j <= 6 && i - j + 1 >= 1; j += 2) {
            transfer(i - j + 1, i);
        }
    }
    cout << dp[n * 2] << endl;
    return 0;
}