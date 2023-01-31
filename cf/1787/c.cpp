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
LL dp[N][22];
vector<PII> ve[N];
int a[N], s;

void push(int idx, int x, int y, int a) {
    if (x + y == a && x >= 0 && y >= 0 && (LL)(x - s) * (y - s) >= 0) {
        ve[idx].push_back({x, y});
    }
}

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
        for (int i = 2; i < n; ++i) {
            ve[i].clear();
            for (int j = 0; j <= 4; ++j) {
                push(i, j, a[i] - j, a[i]);
                push(i, a[i] - j, j, a[i]);
                push(i, a[i] / 2 + j, a[i] - (a[i] / 2 + j), a[i]);
                push(i, a[i] - (a[i] / 2 + j), a[i] / 2 + j, a[i]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            memset(dp[i], 0x3f, sizeof(dp[i]));
        }
        memset(dp[1], 0, sizeof(dp[1]));
        ve[1].clear();
        ve[1].push_back({a[1], a[1]});
        for (int i = 2; i < n; ++i) {
            for (int j = 0; j < ve[i - 1].size(); ++j) {
                for (int k = 0; k < ve[i].size(); ++k) {
                    dp[i][k] = min(dp[i - 1][j] + (LL)ve[i - 1][j].second * ve[i][k].first, dp[i][k]);
                }
            }
        }
        LL ans = 1e18; 
        for (int i = 0; i < ve[n - 1].size(); ++i) {
            ans = min(ans, dp[n - 1][i] + (LL)ve[n - 1][i].second * a[n]);
        }
        cout << ans << endl;
    }
    return 0;
}