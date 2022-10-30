#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];
LL k;
LL pre[N];

bool ok(LL v) {
    LL sum = pre[n] - v;
    for (int i = n, j = 1; i > 1 && j <= v; --i, ++j) {
        LL q = v - j;
        LL c = a[1] - q;
        LL cnt = c + c * j + pre[i - 1] - pre[1];
        sum = min(sum, cnt);
    }
    return sum <= k;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + a[i];
        }
        LL l = 0, r = 1e11, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (ok(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << endl;
    }
    return 0;
}