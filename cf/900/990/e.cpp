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
const int N = 3 + 1e6;

int last[N];
int n, m, k, s[N], a[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> s[i];
        cnt[s[i]] = 1;
    }
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    if (cnt[0]) {
        cout << -1 << endl;
        return 0;
    }
    int mx = 1;
    for (int i = 1; i < n; ++i) {
        if (cnt[i]) {
            last[i] = last[i - 1];
        } else {
            last[i] = i;
        }
        mx = max(mx, i - last[i] + 1);
    }
    if (cnt[0] || mx > k) {
        cout << -1 << endl;
        return 0;
    }
    LL ans = 1e18;
    for (int i = mx; i <= k; ++i) {
        LL temp = 0;
        for (int j = 0; j < n;) {
            if (cnt[j]) {
                j = last[j];
            }
            j += i;
            temp += a[i];
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;

    return 0;
}