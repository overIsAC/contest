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
const int N = 3 + 52;

int n, a[N];
bool dp[250][250][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i][i][a[i]] = 1;
    }
    int ans = 1;
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
            for (int mid = l; mid < r; ++mid) {
                for (int i = 1; i < 45; ++i) {
                    if (!dp[l][mid][i] || !dp[mid + 1][r][i]) {
                        continue;
                    }
                    dp[l][r][i + 1] = 1;
                    ans = max(i + 1, ans);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}