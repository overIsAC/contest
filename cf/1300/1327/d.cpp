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

int p[N], c[N], n;
int vis[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
        }
        int ans = n;
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) {
                continue;
            }
            vector<int> ve;
            int x = i;
            while (!vis[x]) {
                vis[x] = 1;
                x = p[x];
            }
            int y = p[x];
            while (x != y) {
                ve.push_back(y);
                y = p[y];
            }
            ve.push_back(y);

            int m = ve.size();

            auto calc = [&](int v) {
                if (v >= ans) {
                    return;
                }
                for (int i = 0; i < v; ++i) {
                    bool ok = true;
                    for (int j = i; j < m; j += v) {
                        if (c[ve[j]] != c[ve[(j + v) % m]]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        ans = v;
                        return;
                    }
                }
            };

            for (int j = 1; j * j <= m; ++j) {
                if (m % j == 0) {
                    calc(j);
                    calc(m / j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}