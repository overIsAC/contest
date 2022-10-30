#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, k, a[N];
int b[N], now;

int calc(int v) {
    int ans = 0;
    for (int i = 2; i <= v; ++i) {
        if (v % i == 0) {
            while (v % i == 0) {
                v /= i;
            }
            ++ans;
        }
    }
    return ans;
}

int main() {
    assert(cin >> n >> k);
    assert(1 <= k && k <= n && n <= 1e5);
    for (int i = 1; i <= n; ++i) {
        assert(cin >> a[i]);
        assert(1 <= a[i] && a[i] <= 1e4);
    }

    for (int i = 1; i <= n; ++i) {
        b[i] = calc(a[i]);
        now += b[i];
    }

    int ans = 0;
    for (int i = 1, j = 1; i <= n; ++i) {
        now -= b[i];
        if (i - j + 1 == k) {
            ans = max(ans, now);

            now += b[j];
            ++j;
        }
    }
    cout << ans << endl;

    return 0;
}
