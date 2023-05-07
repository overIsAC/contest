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

int n, a[N], q;
int pre[N];

int get(int p) {
    return a[p] >= a[p + 1] && a[p + 1] >= a[p + 2];
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = 1e9 + 2;
    a[n + 2] = 1e9 + 3;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + get(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = pre[r] - pre[l - 1];
        ans -= get(r);
        if (r - 1 >= l) {
            ans -= get(r - 1);
        }
        cout << r - l + 1 - ans << endl;
    }

    return 0;
}