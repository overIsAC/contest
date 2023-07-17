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
const int N = 3 + 3e5;

PII a[N];
int n, k;
LL pre[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    cin >> k;
    LL cnt = 0;
    int l = 1, r = k;
    for (int i = 1; i <= k; ++i) {
        cnt += (LL)i * a[i].first - (LL)(k - i + 1) * a[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i].first;
    }
    db(cnt);
    LL now = cnt;
    for (int i = k + 1; i <= n; ++i) {
        cnt += (LL)(k - 1) * a[i - k].first;
        cnt += (LL)(k - 1) * a[i].first;
        cnt -= 2 * (pre[i - 1] - pre[i - k]);
        // cout << a[i - k].first << ' ' << a[i].first << ' ' << pre[i - 1] - pre[i - k] << endl;
        db(cnt);
        if (now > cnt) {
            now = cnt;
            l = i - k + 1;
            r = i;
        }
    }
    for (int i = l; i <= r; ++i) {
        cout << a[i].second << ' ';
    }

    return 0;
}