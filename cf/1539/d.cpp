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
const int N = 3 + 2e5;

int n;
pair<LL, LL> a[N];
LL pre[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, [](pair<LL, LL>& a, pair<LL, LL>& b) {
        return a.second < b.second;
    });
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i].first;
    }
    LL ans = 0, cnt = 0;
    for (int i = n; i > 0; --i) {
        if (a[i].second <= cnt + pre[i - 1]) {
            ans += a[i].first;
        } else {
            LL t = a[i].second - cnt - pre[i - 1];
            if (a[i].first <= t) {
                ans += a[i].first * 2;
                cnt += a[i].first;
            } else {
                a[i].first -= t;
                ans += 2 * t;
                ans += a[i].first;
                cnt += t;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}