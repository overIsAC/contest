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
const int N = 3 + 4e5;

int n;
map<int, int> mp[N];
PII w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> w[i].first;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> w[i].second;
        }
        sort(w + 1, w + n + 1);
        const int m = sqrt(n * 2);
        for (int i = 1; i <= m; ++i) {
            mp[i].clear();
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            auto [a, b] = w[i];
            if (a <= m) {
                ++mp[a][b];
            } else {
                for (int j = 1; j <= m && j * a <= 2 * n; ++j) {
                    if (mp[j].count(j * a - b)) {
                        ans += mp[j][j * a - b];
                    }
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = i + 1; j <= m; ++j) {
                for (auto& [x, y] : mp[i]) {
                    if (i * j <= x) {
                        break;
                    }
                    if (mp[j].count(i * j - x)) {
                        ans += (LL)mp[j][i * j - x] * y;
                    }
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            LL cnt = 0;
            for (auto& [x, y] : mp[i]) {
                if (i * i == x + x) {
                    ans += (LL)y * (y - 1) / 2;
                } else {
                    if (mp[i].count(i * i - x)) {
                        cnt += (LL)y * mp[i][i * i - x];
                    }
                }
            }
            ans += cnt / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}