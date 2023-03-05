#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, q, a[N];
map<int, int> bin;
int cnt[33];

int main() {
    for (int i = 0; i < 31; ++i) {
        bin[1 << i] = i;
    }
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[bin[a[i]]];
    }
    while (q--) {
        map<int, LL> mm;
        LL ans = 0;
        int b;
        cin >> b;
        for (int i = 0; i < 31; ++i) {
            if (b >> i & 1) {
                ++mm[i];
            }
        }
        for (int i = 30; i >= 0; --i) {
            ans += min((LL)cnt[i], mm[i]);
            if (cnt[i] < mm[i]) {
                mm[i - 1] += (mm[i] - cnt[i]) * 2;
            }
        }
        if (mm[-1])
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}