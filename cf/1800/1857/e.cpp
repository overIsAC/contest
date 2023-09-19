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
PII a[N];
LL pre[N], suf[N];
LL ans[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + a[i].first;
        }
        suf[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            suf[i] = suf[i + 1] + a[i].first;
        }
        for (int i = 1; i <= n; ++i) {
            LL ans = (LL)a[i].first * (i - 1) - pre[i - 1];
            ans += suf[i + 1] - (LL)a[i].first * (n - i);
            ans += n;
            ::ans[a[i].second] = ans;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}