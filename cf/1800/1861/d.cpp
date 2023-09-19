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

int n, a[N];
int pre[N], suf[N];

/*
1
4
4 3 1 2


-4 -3 1 2

*/

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (a[i - 1] <= a[i]) {
            ++pre[i];
        }
    }
    suf[n] = suf[n + 1] = 0;
    for (int i = n - 1; i >= 1; --i) {
        suf[i] = suf[i + 1];
        if (a[i] >= a[i + 1]) {
            ++suf[i];
        }
    }
    int ans = min(suf[1], pre[n] + 1);
    ans = min(ans, suf[2] + 1);
    for (int i = 2; i <= n; ++i) {
        ans = min(ans, pre[i - 1] + 1 + 1 + suf[i + 1]);
        ans = min(ans, pre[i - 1] + 1 + suf[i]);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}