#include <bits/stdc++.h>
using namespace std;
#define int long long
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
LL pre[N], suf[N];
PII a[N];

signed main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, int> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].second;
            m[a[i].first] = max(m[a[i].first], a[i].second);
        }
        n = 0;
        for (auto &i : m) {
            a[++n] = i;
        }
        pre[1] = a[1].second;
        for (int i = 2; i <= n; ++i) {
            pre[i] = max((LL)a[i].second,
                         pre[i - 1] + (a[i].first - a[i - 1].first));
        }
        suf[n] = a[n].second;
        for (int i = n - 1; i; --i) {
            suf[i] = max((LL)a[i].second,
                         suf[i + 1] + (a[i + 1].first - a[i].first));
        }
        long double p = a[1].first;
        long double ans = suf[1];
        if (ans > pre[n]) {
            p = a[n].first;
            ans = pre[n];
        }
        for (int i = 2; i <= n; ++i) {
            if (a[i].first == a[i - 1].first) continue;
            long double dist = a[i].first - a[i - 1].first;
            dist -= abs(pre[i - 1] - suf[i]);
            if (dist < 0) {
                continue;
            }
            long double u = a[i - 1].first, v = a[i].first;
            if (pre[i - 1] < suf[i]) {
                u += suf[i] - pre[i - 1];
            } else {
                v -= pre[i - 1] - suf[i];
            }
            if (ans > max(pre[i - 1], suf[i]) + dist / 2) {
                ans = max(pre[i - 1], suf[i]) + dist / 2;
                p = (u + v) / 2;
            }
        }
        for (int i = 2; i < n; ++i) {
            if (ans > max(pre[i], suf[i])) {
                ans = max(pre[i], suf[i]);
                p = i;
            }
        }
        cout << fixed << setprecision(10) << p << endl;
    }

    return 0;
}