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

int n, k;
LL a[N];
LL dif[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    reverse(a + 1, a + n + 1);
    LL now = 0, cnt = 0;
    LL ans = 0;
    for (int i = 1; i <= n - k; ++i) {
        now -= cnt;
        cnt += dif[i];
        a[i] -= now;
        if (a[i] <= 0) {
            continue;
        }
        LL t = (a[i] + k - 1) / k;
        a[i] -= t * k;
        now += t * k;
        cnt += t;
        ans += t;
        dif[i + k] -= t;
    }
    for (int i = n - k + 1; i <= n; ++i) {
        now -= cnt;
        cnt += dif[i];
        a[i] -= now;
    }

    LL temp = 0;
    for (int i = 1; i <= k; ++i) {
        if (a[n - i + 1] <= 0) {
            continue;
        }
        temp = max(temp, (a[n - i + 1] + i - 1) / i);
    }
    ans += temp;
    cout << ans << endl;

    return 0;
}