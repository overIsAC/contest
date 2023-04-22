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
const int N = 3 + 5555;

int n, t, s;
int a[N], b[N];
map<int, LL> dp1, dp2;

int main() {
    cin >> n >> t >> s;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    dp1[t] = 0;
    auto update = [&](int p, LL v) {
        if (p < s) {
            return;
        }
        if (!dp2.count(p)) {
            dp2[p] = v;
        }
        dp2[p] = max(dp2[p], v);
    };
    for (int i = 1; i <= n; ++i) {
        for (auto &j : dp1) {
            update(j.first, j.second);
            if (j.first % a[i]) {
                continue;
            }
            update(j.first / a[i], j.second + b[i]);
        }
        swap(dp2, dp1);
        dp2.clear();
    }
    LL ans = 0;
    for (auto i : dp1) {
        ans = max(ans, i.second);
    }
    cout << ans << endl;

    return 0;
}