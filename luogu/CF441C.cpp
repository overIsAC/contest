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

int n, m, k;
vector<PII> ans[N];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            for (int j = 1; j <= m; ++j) {
                ans[1].push_back({i, j});
            }
        } else {
            for (int j = m; j >= 1; --j) {
                ans[1].push_back({i, j});
            }
        }
    }
    for (int i = 2; i <= k; ++i) {
        ans[i].push_back(ans[1].back());
        ans[1].pop_back();
        ans[i].push_back(ans[1].back());
        ans[1].pop_back();
    }
    for (int i = 1; i <= k; ++i) {
        cout << ans[i].size() << ' ';
        for (auto &j : ans[i]) {
            cout << j.first << ' ' << j.second << ' ';
        }
        cout << endl;
    }
    return 0;
}