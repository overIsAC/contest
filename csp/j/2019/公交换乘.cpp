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

int op[N], price[N], ti[N];
int vis[N];

int main() {
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> op[i] >> price[i] >> ti[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (op[i] == 0) {
            ans += price[i];
        } else {
            int p = 0;
            for (int j = 1; j <= 45 && i - j > 0; ++j) {
                if (ti[i] - ti[i - j] > 45) {
                    break;
                }
                if (op[i - j] == 0 && !vis[i - j] && price[i - j] >= price[i]) {
                    p = i - j;
                }
            }
            if (p) {
                vis[p] = 1;
            } else {
                ans += price[i];
            }
        }
    }
    cout << ans << endl;

    return 0;
}