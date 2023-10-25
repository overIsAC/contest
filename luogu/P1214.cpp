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
const int N = 3 + 250 * 250 * 2;

int n, m;
int vis[N];
int dp[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            vis[i * i + j * j] = 1;
        }
    }
    vector<PII> ans;
    for (int b = 1; b * (n - 1) <= m * m * 2; ++b) {
        for (int j = m * m * 2; j >= 0; --j) {
            dp[j] = vis[j];
            if (!vis[j]) {
                continue;
            }
            if (j + b <= m * m * 2) {
                dp[j] = max(dp[j], dp[j + b] + 1);
            }
            if (dp[j] >= n) {
                ans.push_back({j, b});
            }
        }
    }
    if (ans.empty()) {
        cout << "NONE" << endl;
    } else {
        for (auto &[x, y] : ans) {
            swap(x, y);
        }
        sort(ans.begin(), ans.end());
        for (auto [x, y] : ans) {
            cout << y << ' ' << x << endl;
        }
    }
    return 0;
}