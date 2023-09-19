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

int ans[N], vis[N];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
        ans[i] = 0;
    }
    vis[x] = 1;
    vis[1] = 1;
    ans[n] = 1;
    ans[1] = x;
    for (int i = n - 1; i > 1; --i) {
        int p = 0;
        for (int j = i; j <= n; j += i) {
            if (!vis[j]) {
                p = j;
                break;
            }
        }
        if (!p) {
            cout << -1 << endl;
            return;
        }
        vis[p] = 1;
        ans[i] = p;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}