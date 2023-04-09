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

int n, q, a[N];
LL pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            LL sum = pre[n] + pre[r] - pre[l - 1] + k % 2 * (r - l + 1);
            sum %= 2;
            cout << (sum ? "YES" : "NO") << endl;
        }
    }
    return 0;
}