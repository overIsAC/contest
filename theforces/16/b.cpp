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
const int N = 3 + 1e5;

int n, a[3][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }
        map<int, int> mp;
        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                mp[a[i][j]] += 1;
            }
        }
        int ans = 0;
        while (mp.count(ans)) {
            ++ans;
        }
        auto fix = [&]() {
            auto f = [&](int v) {
                return v > ans || mp[v] > 1;
            };
            int mx = 0;
            for (int i = 1; i <= n; ++i) {
                if (i % 2) {
                    if (f(a[2][i])) {
                        return;
                    }
                    mx = max(mx, a[2][i]);
                } else {
                    if (f(a[1][i])) {
                        return;
                    }
                    mx = max(mx, a[1][i]);
                }
            }
            ans = mx;
        };
        if (n % 2 == 0) {
            fix();
        }
        cout << ans << endl;
    }
    return 0;
}